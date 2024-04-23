#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <future>
#include <functional>
#include "TreasureMap.h"

namespace seneca{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
           std::ofstream file(filename, std::ios::out | std::ios::binary | std::ios::trunc);
           if (file.is_open())
           {
              if(file)
              {
                 file.write(reinterpret_cast<char*>(&rows), sizeof(rows));

                 file.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));

                 for (size_t i = 0; i < rows; i++)
                 {
                    file.write(&map[i][0], map[i].size());
                 }
                 file.close();
              }
           }
            // END TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
       std::ifstream file(filename, std::ios::in | std::ios::binary);

       if (file.is_open())
       {
          file.read(reinterpret_cast<char*>(&rows), sizeof(size_t));

          file.read(reinterpret_cast<char*>(&colSize), sizeof(size_t));

          map = new std::string[rows];

          for (size_t i = 0; i < rows; i++) {
             map[i].resize(colSize);
             file.read(&map[i][0], colSize);
          };
          file.close();
       }
        // END TODO
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::countTreasureInRange(const std::string* begin, const std::string* end, char mark) {
       size_t count = 0;
       for (const std::string* it = begin; it != end; ++it) {
          count += digForTreasure(*it, mark);
       }
       return count;
    }


    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        //for (size_t i = 0; i < rows; ++i){
        //    count += digForTreasure(map[i], mark);
        //}
        // Get the number of hardware threads
         // Get the number of hardware threads
        size_t numThreads = std::thread::hardware_concurrency();
        std::vector<std::future<size_t>> futures;
        std::vector<std::thread> threads;

        // Partition the data among threads
        size_t chunkSize = rows / numThreads;
        size_t remainder = rows % numThreads;
        size_t startIndex = 0;

        // Create packaged_tasks and futures for each thread
        for (size_t i = 0; i < numThreads; ++i) {
           size_t partitionSize = chunkSize + (i < remainder ? 1 : 0);
           const std::string* start = map + startIndex;
           const std::string* end = start + partitionSize;

           // Create a packaged_task with a lambda function
           std::packaged_task<size_t()> task([=]() { return countTreasureInRange(start, end, mark); });

           // Get the future associated with the packaged_task
           futures.push_back(task.get_future());

           // Launch a thread to execute the task
           threads.emplace_back(std::move(task));

           // Update start index for the next partition
           startIndex += partitionSize;
        }

        // Join threads to ensure they all finish before proceeding
        for (auto& thread : threads) {
           thread.join();
        }

        // Retrieve the results from the futures
        for (auto& fut : futures) {
           count += fut.get();
        }

        return count;
    }
}
// Name:                   Krutin Bharatbhai Polra
// Seneca Student ID:      135416220
// Seneca email:           kbpolra@myseneca.ca
// Date of completion:     24th March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		size_t i;
		size_t j;
		for (i = 0; i < desc.size(); i++)
		{
			for (j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product* listOfProduct = new Product(desc[i].desc, price[j].price);
					if ((desc[i].code))
					{
						try
						{
							listOfProduct->validate();
						}
						catch (std::string err)
						{
							delete listOfProduct;
							throw std::string(err);
						}
					}
					else
					{
						delete listOfProduct;
						throw std::string("*** Negative prices are invalid ***");
					}
					priceList += listOfProduct;
					delete listOfProduct;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		size_t i;
		size_t j;
		for (i = 0; i < desc.size(); i++)
		{
			for (j = 0; j < price.size(); j++)
			{

				if (desc[i].code == price[j].code)
				{
					std::unique_ptr<Product> listOfProduct = std::make_unique<Product>(desc[i].desc, price[j].price);

					if ((desc[i].code)) 
						listOfProduct.get()->validate();
					else 
						throw std::string("*** Negative prices are invalid ***");

					priceList += listOfProduct;
				}
			}
		}
		return priceList;
	}
}
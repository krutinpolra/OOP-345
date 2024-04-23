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

		for (unsigned int i = 0; i < desc.size(); i++)
		{
			for (unsigned int j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product* product = new Product(desc[i].desc, price[j].price);
					if ((desc[i].code))
					{
						try
						{
							product->validate();
						}
						catch (std::string err)
						{
							delete product;
							throw std::string(err);
						}
					}
					else
					{
						delete product;
						throw std::string("*** Negative prices are invalid ***");
					}
					priceList += product;
					delete product;
				}
			}
		}


		return priceList;
	}
}
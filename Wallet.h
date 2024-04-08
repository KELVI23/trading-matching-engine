#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
public:
	Wallet();
	/*Insert currecny to the wallet*/
	void insertCurrency(std::string type, double amount);
	/*remove currecny fromteh wallet*/
	bool removeCurrency(std::string type, double amount);
	/*Does it have the money*/
	bool containsCurrency(std::string type, double amount);
	/*Checks if the wallet has enough to complete order*/
	bool canFulfillOrder(OrderBookEntry order);
	/*update tje contents of the wallet
		assumes the order was made by the owner of the wallet
	*/
	void processSale(OrderBookEntry& sale);

	/*generate string represantaion of wallet*/
	std::string toString();

private:
	std::map<std::string, double> currencies;
};
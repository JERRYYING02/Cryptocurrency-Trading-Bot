#pragma once

#include <string>
#include <map>
#include "OrderBookEntry.h"
#include <iostream>

class Wallet 
{
    public:
        Wallet();
        /** insert currency to the wallet */
        void insertCurrency(std::string type, double amount);
        /** remove currency from the wallet */
        bool removeCurrency(std::string type, double amount);
        
        /** check if the wallet contains this much currency or more */
        bool containsCurrency(std::string type, double amount);
        /** checks if the wallet can cope with this ask or bid.*/

        //IF COULD WE CAN REFERENCE THE ORDER,OR CONST IT AS IT ONLY READ ORDERS
        //BUT WE CANNOT AT CONST BEHIND,IF DO SO ,
        //state of the object will not be affected,
        //BUT CANFULFILLORDER CALLS CONTAINCURRENCY WHO ACCESS CURRENCY DATA WITH [TYPE]
        bool canFulfillOrder(OrderBookEntry order);
        /** update the contents of the wallet
         * assumes the order was made by the owner of the wallet
        */
        void processSale(OrderBookEntry& sale);


        /** generate a string representation of the wallet */
        std::string toString();
        friend std::ostream& operator<<(std::ostream& os, Wallet& wallet);

        
    private:
        std::map<std::string,double> currencies;

};



	


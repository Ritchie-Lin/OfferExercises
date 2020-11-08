#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "util/util.h"

using namespace std;

/**
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计
 * 一个算法来计算你所能获取的最大利润。
 * 注意你不能在买入股票前卖出股票。
 * @param prices 整型数组
 * @param pricesLen 整形数组元素个数
 * @version 1.0
 * @author Ritchie.Lin
 */
int MaxProfitOneShoot(int prices[], int pricesLen)
{
    if (prices == NULL || pricesLen <= 1)
        return 0;
    
    // buyStock表示第i天买入的话，买入股票的最大收益。
    // 1. 当天的价格最低
    // 2. 之前的价格最低
    int buyStock[pricesLen] = {0};
    buyStock[0] = -prices[0];

    // sellStock表示第i天卖出股票的话，能获得的最大收益。
    // 1. 之前全部卖出
    // 2. 当前卖出利润最大
    int sellStock[pricesLen] = {0};
    sellStock[0] = 0;

    for (int i = 1; i < pricesLen; i++)
    {
        buyStock[i] = max(buyStock[i-1], -prices[i]);
        sellStock[i] = max(sellStock[i-1], prices[i] + buyStock[i-1]);
    }

    cout << "buy stock: " << TransferNumToStr(buyStock, pricesLen) << endl;
    cout << "sell stock: " << TransferNumToStr(sellStock, pricesLen) << endl;

    return sellStock[pricesLen - 1];
}

/**
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。
 * 你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * @param prices 整型数组
 * @param pricesLen 整形数组元素个数
 * @version 1.0
 * @author Ritchie.Lin
 */
int MaxProfit(int prices[], int pricesLen)
{
    if (prices == NULL || pricesLen <= 1)
        return 0;
    
    // buyStock表示第i天买入的话，买入股票的最大收益。
    // 1. 当天的价格最低
    // 2. 之前的价格最低
    int buyStock[pricesLen] = {0};
    buyStock[0] = -prices[0];

    // sellStock表示第i天卖出股票的话，能获得的最大收益。
    // 1. 之前全部卖出
    // 2. 当前卖出利润最大
    int sellStock[pricesLen] = {0};
    sellStock[0] = 0;

    for (int i = 1; i < pricesLen; i++)
    {
        buyStock[i] = max(buyStock[i-1], sellStock[i-1] - prices[i]);
        sellStock[i] = max(sellStock[i-1], prices[i] + buyStock[i-1]);
    }

    cout << "buy stock: " << TransferNumToStr(buyStock, pricesLen) << endl;
    cout << "sell stock: " << TransferNumToStr(sellStock, pricesLen) << endl;

    return sellStock[pricesLen - 1];
}

int main(int argc, char* argv[])
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int len = sizeof(prices)/sizeof(int);
    int maxProfit = MaxProfitOneShoot(prices, len);

    cout << "The max profit is " << maxProfit << endl;

    return 0;
}

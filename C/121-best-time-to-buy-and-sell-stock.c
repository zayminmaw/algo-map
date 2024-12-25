int maxProfit(int* prices, int pricesSize) {
    int i = 0, min = prices[0], maxProfit = 0;

    while (i < pricesSize)
    {
        if (min > prices[i])
        {
            min = prices[i];
        }
        else 
        {
            maxProfit = ((prices[i] - min) > maxProfit ? prices[i] - min : maxProfit);
        }
        i++;
    }
    
    return (maxProfit);
}
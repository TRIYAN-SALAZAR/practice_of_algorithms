#include <vector>
#include <iostream>

std::vector<int> productArray(const std::vector<int> &numbers)
{
    int size = numbers.size();
    std::vector<int> products;

    for (int i = 0; i < size; i++)
    {
        int j = 0, product = 1;
        do
        {
            if (j != i)
                product *= numbers[j];
            j++;
        } while (j < size);
        products.push_back(product);
    }
    return products;
}
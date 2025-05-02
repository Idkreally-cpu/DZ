using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var products = new string[] { "Хлеб", "Молоко", "Яйца", "Сахар", "Масло" };
        var prices = new double[] { 50.0, 80.5, 120.0, 65.3, 150.0 };

        PrintProductsWithPrices(products, prices);

        double averagePrice = CalculateAveragePrice(prices);
        Console.WriteLine($"\nСредняя цена товаров: {averagePrice:F2} руб.");
    }

    static void PrintProductsWithPrices(params object[] arrays)
    {
        if (arrays.Length < 2 || !(arrays[0] is string[]) || !(arrays[1] is double[]))
        {
            Console.WriteLine("Ошибка: неверные параметры");
            return;
        }

        var products = (string[])arrays[0];
        var prices = (double[])arrays[1];

        Console.WriteLine("Список товаров с ценами:");
        for (int i = 0; i < products.Length; i++)
        {
            Console.WriteLine($"{products[i]} - {prices[i]:F2} руб.");
        }
    }

    static double CalculateAveragePrice(params double[] prices)
    {
        return prices.Average();
    }
}

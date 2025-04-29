using System;

class Program
{
    static void Main()
    {
        Console.Write("Введите количество строк: ");
        int rows = int.Parse(Console.ReadLine());
        Console.Write("Введите количество столбцов: ");
        int cols = int.Parse(Console.ReadLine());

        int[,] array = new int[rows, cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write($"Введите элемент [{i},{j}]: ");
                array[i, j] = int.Parse(Console.ReadLine());
            }
        }

        Console.WriteLine("Массив в обратном порядке:");
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                Console.Write(array[i, j] + " ");
            }
            Console.WriteLine();
        }
    }
}

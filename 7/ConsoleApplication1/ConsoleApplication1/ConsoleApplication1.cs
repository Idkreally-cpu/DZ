using System;

class Program
{
    static void RemoveFirst(ref int[] array, out int removedElement)
    {
        if (array.Length == 0)
        {
            removedElement = default;
            return;
        }

        removedElement = array[0];
        int[] newArray = new int[array.Length - 1];
        Array.Copy(array, 1, newArray, 0, newArray.Length);
        array = newArray;
    }

    static void RemoveLast(ref int[] array, out int removedElement)
    {
        if (array.Length == 0)
        {
            removedElement = default;
            return;
        }

        removedElement = array[array.Length - 1];
        int[] newArray = new int[array.Length - 1];
        Array.Copy(array, 0, newArray, 0, newArray.Length);
        array = newArray;
    }

    static void RemoveAt(ref int[] array, int index, out int removedElement)
    {
        if (index < 0 || index >= array.Length)
        {
            removedElement = default;
            return;
        }

        removedElement = array[index];
        int[] newArray = new int[array.Length - 1];
        Array.Copy(array, 0, newArray, 0, index);
        Array.Copy(array, index + 1, newArray, index, newArray.Length - index);
        array = newArray;
    }

    static void Main()
    {
        int[] numbers = { 1, 2, 3, 4, 5 };

        RemoveFirst(ref numbers, out int first);
        Console.WriteLine($"Удален первый элемент: {first}");
        Console.WriteLine($"Массив: [{string.Join(", ", numbers)}]");

        RemoveLast(ref numbers, out int last);
        Console.WriteLine($"Удален последний элемент: {last}");
        Console.WriteLine($"Массив: [{string.Join(", ", numbers)}]");

        RemoveAt(ref numbers, 1, out int atIndex);
        Console.WriteLine($"Удален элемент по индексу 1: {atIndex}");
        Console.WriteLine($"Массив: [{string.Join(", ", numbers)}]");
    }
}

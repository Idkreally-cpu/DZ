using System;
using System.Collections.Generic;

public class Book
{
    public string Title { get; set; }
    public string Author { get; set; }
    public int Year { get; set; }
    public int Id { get; set; }
}

public class Library
{
    private Dictionary<int, Book> _books = new Dictionary<int, Book>();

    public void AddBook(Book book)
    {
        _books[book.Id] = book;
    }

    public void RemoveBook(int id)
    {
        _books.Remove(id);
    }

    public Book FindBook(int id)
    {
        return _books.TryGetValue(id, out var book) ? book : null;
    }

    public void ListBooks()
    {
        foreach (var book in _books.Values)
        {
            Console.WriteLine($"ID: {book.Id}, Название: {book.Title}, Автор: {book.Author}, Год: {book.Year}");
        }
    }
}

class Program
{
    static void Main()
    {
        Library library = new Library();

        library.AddBook(new Book { Id = 1, Title = "Война и мир", Author = "Лев Толстой", Year = 1869 });
        library.AddBook(new Book { Id = 2, Title = "Преступление и наказание", Author = "Фёдор Достоевский", Year = 1866 });

        Console.WriteLine("Все книги:");
        library.ListBooks();

        Console.WriteLine("\nНайдена книга с ID=1:");
        var foundBook = library.FindBook(1);
        if (foundBook != null)
            Console.WriteLine($"Название: {foundBook.Title}, Автор: {foundBook.Author}");

        library.RemoveBook(2);
        Console.WriteLine("\nПосле удаления книги с ID=2:");
        library.ListBooks();
    }
}

using System;

class Company
{
    public string Name { get; set; }
    public string Address { get; set; }
}

class User
{
    public string Name { get; set; }
    public Company Company { get; set; }
}

class Program
{
    static void Main()
    {
        User user1 = new User { Name = "Иван Иванов" };
        User user2 = new User 
        { 
            Name = "Петр Петров", 
            Company = new Company { Name = "ООО Ромашка" } 
        };
        User user3 = new User 
        { 
            Name = "Сидор Сидоров", 
            Company = new Company { Name = "ИП Солнышко", Address = "ул. Ленина, 1" } 
        };

        DisplayUserInfo(user1);
        DisplayUserInfo(user2);
        DisplayUserInfo(user3);
    }

    static void DisplayUserInfo(User user)
    {
        Console.WriteLine($"Пользователь: {user.Name}");
        Console.WriteLine($"Компания: {user.Company?.Name ?? "не указана"}");
        Console.WriteLine($"Адрес: {user.Company?.Address ?? "не указан"}");
        Console.WriteLine();
    }
}

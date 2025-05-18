using System;

public class Student
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Performance { get; set; }
}

public static class StudentExtensions
{
    public static void PrintInfo(this Student student)
    {
        Console.WriteLine($"{student.FirstName} {student.LastName}: {student.Performance}");
    }
}

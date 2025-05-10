using System;

public class Student
{
    public string Name { get; set; }
    public int Age { get; set; }
    public Group Group { get; set; }
    public double AverageGrade { get; set; }

    public void PrintInfo()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}, Group: {Group}, Average Grade: {AverageGrade}");
    }
}

public enum Group
{
    CS101,
    CS202,
    CS303,
    MATH101,
    PHYS202
}

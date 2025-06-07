using System;

class Thermometer
{
    private double _temperature;
    public double Temperature
    {
        get => _temperature;
        set
        {
            if (_temperature != value)
            {
                _temperature = value;
                OnTemperatureChanged();
            }
        }
    }

    public event Action<double> TemperatureChanged;

    protected virtual void OnTemperatureChanged()
    {
        TemperatureChanged?.Invoke(_temperature);
    }
}

class AirConditioner
{
    public void ReactToTemperature(double temp)
    {
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"AirConditioner: Temperature changed to {temp}°C");
        Console.ResetColor();
    }
}

class WarningSystem
{
    public void ReactToTemperature(double temp)
    {
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"WarningSystem: Temperature changed to {temp}°C");
        Console.ResetColor();
    }
}

class Program
{
    static void Main()
    {
        var thermometer = new Thermometer();
        var ac = new AirConditioner();
        var ws = new WarningSystem();

        thermometer.TemperatureChanged += ac.ReactToTemperature;
        thermometer.TemperatureChanged += ws.ReactToTemperature;

        thermometer.Temperature = 25;
        thermometer.Temperature = 30;
    }
}

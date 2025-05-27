interface Weapon
{
    void Attack();
}

interface RangedWeapon : Weapon
{
    void Reload();
}

interface MeleeWeapon : Weapon
{
    void Sharpen();
}

interface ThrowableWeapon : Weapon
{
    void Throw();
}

class Sword : MeleeWeapon
{
    public void Attack() => Console.WriteLine("Slash!");
    public void Sharpen() => Console.WriteLine("Sharpening the sword.");
}

class Bow : RangedWeapon
{
    public void Attack() => Console.WriteLine("Shoot an arrow!");
    public void Reload() => Console.WriteLine("Reloading the bow.");
}

class Knife : MeleeWeapon, ThrowableWeapon
{
    public void Attack() => Console.WriteLine("Stab!");
    public void Sharpen() => Console.WriteLine("Sharpening the knife.");
    public void Throw() => Console.WriteLine("Throwing the knife.");
}

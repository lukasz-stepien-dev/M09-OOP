// Łukasz Stępień 4E gr. 2
using Contacts;

public class Program
{
    private const int MaxContacts = 100;
    private List<Contact> Contacts { get; set; } = new List<Contact>();

    public string AddContact(Contact contact)
    {
        if (Contacts.Count < MaxContacts)
        {
            Contacts.Add(contact);
            return "Kontakt dodany.";
        }
        else
        {
            return "Brak miejsca na nowy kontakt.";
        }
    }

    public string RemoveContact(int index)
    {
        Contacts.RemoveAt(index);
        return "Kontakt usunięty.";
    }

    public void ShowContacts()
    {
        Console.WriteLine("-------------------------");
        for (int i = 0; i < Contacts.Count; i++)
        {
            Console.Write($"{i + 1}. ");
            Console.Write($"{Contacts[i].FirstName} {Contacts[i].LastName}, ");
            Console.Write($"Tel: {Contacts[i].PhoneNumber}, ");
            Console.Write($"Email: {Contacts[i].Email}");
            Console.WriteLine();
        }
        Console.WriteLine("-------------------------");
    }

    public bool isOnlyLetters(string text)
    {
        char[] textArray = text.ToCharArray();
        foreach (var c in textArray)
        {
            if (!Char.IsLetter(c))
            {
                return false;
            }
        }

        return true;
    }

    public bool ValidateDate(string firstName, string lastName, string phoneNumber, string email)
    {
        if (!isOnlyLetters(firstName) || !isOnlyLetters(lastName))
        {
            return false;
        }

        char[] numberArray = phoneNumber.ToCharArray();
        foreach (var c in numberArray)
        {
            if (!Char.IsDigit(c))
            {
                return false;
            }
        }

        if (!email.Contains('@'))
        {
            return false;
        }

        return true;
    }

    public void Menu(int choice)
    {
        switch (choice)
        {
            case 1:
                string firstName, lastName, email, phoneNumber;
                Console.WriteLine("Podaj imię:");
                firstName = Console.ReadLine();

                Console.WriteLine("Podaj nazwisko:");
                lastName = Console.ReadLine();

                Console.WriteLine("Podaj numer telefonu:");
                phoneNumber = Console.ReadLine();

                Console.WriteLine("Podaj email:");
                email = Console.ReadLine();

                if (ValidateDate(firstName, lastName, phoneNumber, email))
                {
                    Console.WriteLine(AddContact(new Contact(firstName, lastName, int.Parse(phoneNumber), email)));
                }
                else
                {
                    Console.WriteLine("Niepoprawne dane.");
                }
                break;
            case 2:
                ShowContacts();
                break;
            case 3:
                if (Contacts.Count > 0)
                {
                    Console.WriteLine("Podaj numer kontaktu do usunięcia:");
                    int index = int.Parse(Console.ReadLine());
                    Console.WriteLine(RemoveContact(index - 1));
                }
                else
                {
                    Console.WriteLine("Brak kontaktów.");
                }
                break;
        }
    }

    public static void Main(string[] args)
    {
        Program program = new Program();
        int choice;
        do
        {
            Console.WriteLine("----------------------------");
            Console.WriteLine("Wybierz opcję:");
            Console.WriteLine("1. Dodaj kontakt");
            Console.WriteLine("2. Pokaż kontakty");
            Console.WriteLine("3. Usuń kontakt");
            Console.WriteLine("4. Wyjdź");
            Console.WriteLine("----------------------------");
            choice = int.Parse(Console.ReadLine());
            program.Menu(choice);
        } while (choice != 4);
    }
}
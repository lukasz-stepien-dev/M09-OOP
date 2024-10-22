// Łukasz Stępień 4E gr. 2 21.10.2024

public class Contact
{
    public string firstName { get; set; };
    public string lastName { get; set; };
    public int phoneNumber { get; set; };
    public string email { get; set; };

    public Contact(string firstName, string lastName, int phoneNumber, string email)
    {
        this.firstName = firstName;
        this.lastName = lastName;
        this.phoneNumber = phoneNumber;
        this.email = email;
    }
    
}

public class Lukasz_Stepien_4E_gr2
{
    Contact[100] contacts;
    public string AddContact(Contact contact)
    {
        contacts[contacts.Length] = contact;
        return "Kontakt dodany.";
    }

    public void Menu(int choice)
    {
        switch (choice)
        {
            case 1:
            
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }
    
    public static void Main(string[] args)
    {
        
    }
}
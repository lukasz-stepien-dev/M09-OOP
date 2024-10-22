// Łukasz Stępień 4E gr. 2
namespace Contacts;

public class Contact(string FirstName, string LastName, int PhoneNumber, string Email)
{
    public string FirstName { get; set; } = FirstName;
    public string LastName { get; set; } = LastName;
    public int PhoneNumber { get; set; } = PhoneNumber;
    public string Email { get; set; } = Email;
}
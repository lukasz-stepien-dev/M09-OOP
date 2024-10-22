// Łukasz Stępień 4E gr. 2 21.10.2024

using System;
using System.Collections.Generic;
using System.Linq;

public class DiceGame
{
    private Random random = new Random();
    
    public void Start()
    {
        bool continueGame = true;

        while (continueGame)
        {
            int numberOfDice = GetNumberOfDice();
            List<int> rolls = RollDice(numberOfDice);
            DisplayRolls(rolls);
            int points = CalculatePoints(rolls);
            Console.WriteLine($"Liczba uzyskanych punkow: {points}");
            continueGame = AskToContinue();
        }
    }

    private int GetNumberOfDice()
    {
        int numberOfDice;
        do
        {
            Console.Write("Ile kostek chcesz rzucic?(3 - 10): ");
            numberOfDice = int.Parse(Console.ReadLine());
        } while (numberOfDice < 3 || numberOfDice > 10);
        
        return numberOfDice;
    }

    private List<int> RollDice(int numberOfDice)
    {
        List<int> rolls = new List<int>();
        for (int i = 0; i < numberOfDice; i++)
        {
            rolls.Add(random.Next(1, 7));
        }
        return rolls;
    }

    private void DisplayRolls(List<int> rolls)
    {
        for (int i = 0; i < rolls.Count; i++)
        {
            Console.WriteLine($"Kostka {i + 1}: {rolls[i]}");
        }
    }

    private int CalculatePoints(List<int> rolls)
    {
        int points = 0;
        var groupedRolls = rolls.GroupBy(r => r)
                                .Where(g => g.Count() > 1)
                                .ToDictionary(g => g.Key, g => g.Count());

        foreach (var group in groupedRolls)
        {
            points += group.Key * group.Value;
        }

        return points;
    }

    private bool AskToContinue()
    {
        Console.Write("Jeszcze raz? (t/n): ");
        string response = Console.ReadLine().ToLower();
        return response == "t";
    }

    public static void Main(string[] args)
    {
        DiceGame game = new DiceGame();
        game.Start();
    }
}

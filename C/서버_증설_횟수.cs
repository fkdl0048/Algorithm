using System;

public class Solution 
{
    public int solution(int[] players, int m, int k) 
    {
        Server server = new Server(m, k);
        return server.GetOneDayMinServerCount(players);
    }
}

public class Server
{
    private readonly int serverDurationHours;
    private readonly int capacityPerServer;
    
    public Server(int m, int k)
    {
        capacityPerServer = m;
        serverDurationHours = k;
    }
    
    public int GetOneDayMinServerCount(int[] players)
    {
        int result = 0;
        int n = 24;
        int[] end = new int[n + serverDurationHours + 1];
        int active = 0;
        
        for (int i = 0; i < n; i++)
        {
            int req = players[i] / capacityPerServer;

            active -= end[i];

            int need = req - active;
            if (need > 0)
            {
                active += need;
                result += need;
                end[i + serverDurationHours] += need;
            }
        }
        return result;
    }
}
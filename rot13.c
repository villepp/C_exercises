void rot13(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90))
        {
            if (s[i] > 109 || (s[i] > 77 && s[i] < 91))
            {
                s[i] -= 13;
            }
            else
            {
                s[i] += 13;
            }
        }
        i++
    }
}
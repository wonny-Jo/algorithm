#include <stdio.h> 
#include <algorithm> 

struct Base36
{
	int c, d[52];
} base[36], r;

void Mul(Base36& r, const Base36& a, int m)
{
	for (int i = 0, c = 0; i < 52; i++)
	{
		r.d[i] = a.d[i] * m + c;
		c = r.d[i] / 36;
		r.d[i] %= 36;
	}
}

bool cmp(int a, int b)
{
	Base36 ta, tb;
	Mul(ta, base[a], 35 - base[a].c);
	Mul(tb, base[b], 35 - base[b].c);
	for (int i = 51; i >= 0; i--)
	{
		if (ta.d[i] > tb.d[i])
			return true;
		if (ta.d[i] < tb.d[i])
			return false;
	}
	return false;
}

int main()
{
	int i, j, n, k, t, c, idx[36];
	for (i = 0; i < 36; i++)
		base[i].c = i, idx[i] = i;
	scanf("%d", &n);
	while (n--)
	{
		char s[56];
		scanf("%s", s);
		for (k = 0; s[k]; k++)
			s[k] = (s[k] < 'A') ? s[k] - '0' : s[k] - 'A' + 10;
		for (t = 0, i = k - 1; i >= 0; i--, t++)
			base[s[i]].d[t]++;
	}
	std::sort(idx, idx + 35, cmp);
	scanf("%d", &k);
	for (i = 0; i < k; i++)
		base[idx[i]].c = 35;
	for (i = 0, c = 0; i < 52; i++)
	{
		for (j = 0, t = c; j < 36; j++)
			t += base[j].c * base[j].d[i];
		r.d[i] = t % 36; c = t / 36;
	}
	for (i = 51, t = 0; i >= 0; i--)
	{
		if (t || r.d[i] || !i)
			putchar(r.d[i] < 10 ? r.d[i] + '0' : r.d[i] + 'A' - 10), t = 1;
	}
	putchar('\n');
}

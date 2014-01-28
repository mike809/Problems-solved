/*
Description

Farmer John has discovered that his cows produce higher quality milk when they
are subject to strenuous exercise. He therefore decides to send his N cows (1 <= N <= 25,000)
to climb up and then back down a nearby mountain!

Cow i takes U(i) time to climb up the mountain and then D(i) time to climb down the mountain.
Being domesticated cows, each cow needs the help of a farmer for each leg of the climb, 
but due to the poor economy, there are only two farmers available, Farmer John and his cousin Farmer Don.
FJ plans to guide cows for the upward climb, and FD will then guide the cows for the downward climb.
Since every cow needs a guide, and there is only one farmer for each part of the voyage,
at most one cow may be climbing upward at any point in time (assisted by FJ),
and at most one cow may be climbing down at any point in time (assisted by FD).
A group of cows may temporarily accumulate at the top of the mountain if they climb up
and then need to wait for FD's assistance before climbing down. Cows may climb down in a different order
than they climbed up.

Please determine the least possible amount of time for all N cows to make the entire journey.

Link to the problem http://coj.uci.cu/24h/problem.xhtml?abb=1990

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class dos
{
public:
		int up;
		int down;
};

bool cmp(dos a, dos b)
{
		if(((a.up - a.down) < 0) && ((b.up - b.down) < 0))
		{
				if(a.up > b.up)
						return true;
				else if(a.up == b.up)
						return a.down < b.down;

				return false;
		}
		else if(((a.up - a.down) < 0) ^ ((b.up - b.down) < 0))
				return (a.up - a.down) > (b.up - b.down);

		else return a.down < b.down;
};

class comp
{
public:
		bool operator()(int a, int b)
		{
				return a < b;
		}
};

int main()
{
		int c;
		cin >> c;
		dos times[c];
		priority_queue<int, vector<int>, comp> t_down;

		for(int i = 0;i < c;i++)
				cin >> times[i].up >> times[i].down;

		sort(times, times + c, cmp);

		c--;
		int result = times[c].up;
		int last;
		t_down.push(times[c].down);
		c--;

		do
		{
				last = t_down.top();
				t_down.pop();

				if(last >= times[c].up)
				{
						result += last;
						last -= times[c].up;
						t_down.push(times[c].down);
						c--;

						while(c >= 0 && last > 0)
						{
								if(last >= times[c].up)
								{
										last -= times[c].up;
										t_down.push(times[c].down);
										c--;
								}
								else
								{
										times[c].up -= last;
										break;
								}
						}
				}

				else
				{
						result += times[c].up;
						times[c].up -= last;

						if(t_down.empty())
						{
								t_down.push(times[c].down);
								c--;
								continue;
						}

						while(!t_down.empty() && times[c].up > 0)
						{
								if(t_down.top() > times[c].up)
								{
										int tmp = t_down.top();
										t_down.pop();
										tmp -= times[c].up;
										t_down.push(tmp);
								}
								else if(t_down.top() < times[c].up)
								{
										times[c].up -= t_down.top();
										t_down.pop();
										if(!t_down.empty())
												continue;
								}
								else
										t_down.pop();

								t_down.push(times[c].down);
								c--;
								break;
						}
				}
		}while(c >= 0);

		while(!t_down.empty())
		{
				result += t_down.top();
				t_down.pop();
		}
		cout << result << endl;
		return 0;
}
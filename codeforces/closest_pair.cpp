#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
struct point
{
    long x, y;
};
 
int cmpX(point p1, point p2)
{ //to sort according to x value
    return (p1.x < p2.x);
}
 
int cmpY(point p1, point p2)
{ //to sort according to y value
    return (p1.y < p2.y);
}
 
float dist(point p1, point p2)
{ //find distance between p1 and p2
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
 
float findMinDist(point pts[], int n, point pair[])
{ //find minimum distance between two points in a set
    float min = 1000000;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(pts[i], pts[j]) < min)
            {
                min = dist(pts[i], pts[j]);
                if (min < dist(pair[0], pair[1]))
                {
                    pair[0] = pts[i];
                    pair[1] = pts[j];
                }
            }
    return min;
}
 
float min(float a, float b)
{
    return (a < b) ? a : b;
}
 
float stripClose(point strip[], int size, float d, point pair[])
{ //find closest distance of two points in a strip
    float min = d;
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
            {
                min = dist(strip[i], strip[j]);
                if (min < dist(pair[0], pair[1]))
                {
                    pair[0] = strip[i];
                    pair[1] = strip[j];
                }
            }
 
    return min;
}
 
float findClosest(point xSorted[], point ySorted[], int n, point pair[])
{
    if (n <= 3)
        return findMinDist(xSorted, n, pair);
    int mid = n / 2;
 
    point midPoint = xSorted[mid];
    point ySortedLeft[mid + 1];      // y sorted points in the left side
    point ySortedRight[n - mid - 1]; // y sorted points in the right side
    int leftIndex = 0, rightIndex = 0;
 
    for (int i = 0; i < n; i++)
    { //separate y sorted points to left and right
        if (ySorted[i].x <= midPoint.x)
            ySortedLeft[leftIndex++] = ySorted[i];
        else
            ySortedRight[rightIndex++] = ySorted[i];
    }
 
    float leftDist = findClosest(xSorted, ySortedLeft, mid, pair);
    float rightDist = findClosest(xSorted + mid, ySortedRight, n - mid, pair);
    float dist = min(leftDist, rightDist);
 
    point strip[n]; //hold points closer to the vertical line
    int j = 0;
 
    for (int i = 0; i < n; i++)
        if (abs(ySorted[i].x - midPoint.x) < dist)
        {
            strip[j] = ySorted[i];
            j++;
        }
    return min(dist, stripClose(strip, j, dist, pair)); //find minimum using dist and closest pair in strip
}
 
float closestPair(point pts[], int n, point pair[])
{ //find distance of closest pair in a set of points
    point xSorted[n];
    point ySorted[n];
 
    for (int i = 0; i < n; i++)
    {
        xSorted[i] = pts[i];
        ySorted[i] = pts[i];
    }
 
    sort(xSorted, xSorted + n, cmpX);
    sort(ySorted, ySorted + n, cmpY);
    return findClosest(xSorted, ySorted, n, pair);
}
 
void readData(int num, point P[])
{
    for (int i = 0; i < num; i++)
    {
        cin >> P[i].x;
        cin >> P[i].y;
    }
}
 
void copy(point P[], point Q[], int num)
{
    for (int i = 0; i < num; i++)
    {
        Q[i] = P[i];
    }
}
 
int *findIndex(point Q[], point pair[], int num)
{
    int *arr = new int[2];
    for (int i = 0; i < num; i++)
    {
        if (Q[i].x == pair[0].x && Q[i].y == pair[0].y)
            arr[0] = i;
        else if (Q[i].x == pair[1].x && Q[i].y == pair[1].y)
            arr[1] = i;
    }
    if (arr[0] > arr[1])
    {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
    return arr;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    point pair[2];
    
    int num;
    cin >> num;
    point P[num], Q[num];
    readData(num, P);
    copy(P, Q, num);
 
    pair[0].x = 0, pair[0].y = 0;
    pair[1].x = 9999, pair[1].y = 9999;
    float min = closestPair(P, num, pair);
    int *arr = findIndex(Q, pair, num);
    cout << fixed;
    cout.precision(6);
    cout << arr[0] << " " << arr[1] << " " << min;
    delete (arr);
    return 0;
}


#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int main()
{
    // for (int i = 4; i <= 50; i++)
    // {
    //     char foldername[20];
    //     sprintf(foldername, "testcase/test%d", i);
    //     // Creating a directory
    //     if (mkdir(foldername, 0777) == -1)
    //         cerr << "Error :  " << strerror(errno) << endl;

    //     else
    //         cout << "Directory created";
    // }
    char oldname[30];
    char newname[30];
    for (int i = 4; i <= 50; i++)
    {
        sprintf(oldname, "test/test%d.txt", i);
        sprintf(newname, "testcase/test%d/bakery.inp", i);
        /*	Deletes the file if exists */
        if (rename(oldname, newname) != 0)
            perror("Error renaming file");
        else
            cout << "File renamed successfully";
    }

    return 0;
}
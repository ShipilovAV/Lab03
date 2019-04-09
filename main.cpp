#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}


void find_minmax(vector<double> numbers,size_t number_count, double& min, double& max)
{
    min = numbers[0], max = numbers[0];
    for(int i = 0; i < number_count; i++)
    {
        if(numbers[i]< min)
        {
            min = numbers[i];
        }
        else if(numbers[i]> max)
        {
            max = numbers[i];
        }
    }

}

vector <size_t>
make_histogram(double min, double max, size_t bin_count, const vector <double>& numbers)
{

    vector <size_t> bins(bin_count);
    const double h = (max-min)/bin_count;
    for(double number : numbers)
    {
        size_t i = 0;

        while(number >= min + h * (i+1))
        {
            i++;
        }
        if(i>=bin_count)
        {
            i = bin_count-1;
        }
        bins[i] ++;
    }
    return bins;

}

void
show_histogram_text(const vector <size_t>& bins,size_t number_count)
{
    size_t max_bins = bins[0];
    for(size_t bin : bins)
    {
        if(bin > max_bins)
        {
            max_bins = bin;
        }
    }
    size_t MAX_WIGTH;
    cout << "Enter MAX_WIGTH: ";
    cin >> MAX_WIGTH;
    while (true)
    {
        if (MAX_WIGTH > 80 || MAX_WIGTH < 7 || MAX_WIGTH < number_count/3)
        {
            cout << "MAX_WIGTH incorrect \n";
            cout << "Enter MAX_WIGTH: ";
            cin >> MAX_WIGTH;
        }
        else
            break;

    }

    for(size_t bin : bins)
    {
        if(bin < 100)
        {
            cout << " ";
        }
        if(bin < 10)
        {
            cout << " ";
        }
        cout << bin << '|';
        double koef = 1;
        if( max_bins > MAX_WIGTH)
        {
            koef = (double)MAX_WIGTH/max_bins;
        }
        for(size_t i = 0; i < bin*koef; i++)
        {

            cout << '*';
        }
        cout << "\n";
    }

}


int main()
{

    size_t number_count;
    cin >> number_count;
    const  auto numbers = input_numbers(number_count);
    int bin_count;
    cerr << "Enter bin_count: ";
    cin >> bin_count;


    double min, max;
    find_minmax(numbers,number_count, min, max);


    const auto bins = make_histogram(min, max, bin_count, numbers);

    show_histogram_text(bins, number_count);


    return 0;
}

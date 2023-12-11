// Min-Max Normalization and Z-Score
// Normalization is required to transform the data into another format that is more understandable  + to minimize or exclude the duplicated data.
// Z-Score is zero-mean standard-deviation that scales the data where average is taken as zero and mean deviation is taken as one.
#include <bits/stdc++.h>
using namespace std;

void minMaxNormalization(vector<double>& data) {
    double minVal = *min_element(data.begin(), data.end());
    double maxVal = *max_element(data.begin(), data.end());

    for (double& value : data) {
        value = (value - minVal) / (maxVal - minVal);
    }
}

void zScoreNormalization(vector<double>& data) 
{
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    double mean = sum / data.size();
    double varianceSum = 0.0;
    for (double value : data) {
        varianceSum += pow(value - mean, 2);
    }

    double variance = varianceSum / data.size()-1;
    double stdDev = sqrt(variance);
    for (double& value : data) {
        value = (value - mean) / stdDev;
    }
}

int main() 
{
    ifstream inputFile("input.txt");
    ofstream outputFileMinMax("output_minmax.txt");
    ofstream outputFileZScore("output_zscore.txt");
    vector<double> data;
    double value;
    while (inputFile >> value) {
        data.push_back(value);
    }
    vector<double> dataMinMax = data; // Create a copy for min-max normalization
    minMaxNormalization(dataMinMax);
    vector<double> dataZScore = data; // Create a copy for z-score normalization
    zScoreNormalization(dataZScore);
    for (const double& normalizedValue : dataMinMax) {
        outputFileMinMax << normalizedValue << endl;
    }
    for (const double& normalizedValue : dataZScore) {
        outputFileZScore << normalizedValue << endl;
    }
    inputFile.close();
    outputFileMinMax.close();
    outputFileZScore.close();
    return 0;
}
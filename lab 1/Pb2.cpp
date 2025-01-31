#include <iostream>
using namespace std;

void calculateAQI(float data[][28], string names[], int cities, int days) {
    float cityavg[4], maxAQI = -1;
    int worstCity = -1;
    
    for (int i = 0; i < cities; i++) {
        float sum = 0;
        for (int j = 0; j < days; j++) sum += data[i][j];
        cityavg[i] = sum / days;
        cout << "Average AQI for " << names[i] << ": " << cityavg[i] << endl;
        
        if (cityavg[i] > maxAQI) {
            maxAQI = cityavg[i];
            worstCity = i;
        }
    }
    cout << "The worst city with the highest AQI is " << names[worstCity] << endl;
}

void criticalPollutionDays(float data[][28], string names[], int cities, int days) {
    for (int i = 0; i < cities; i++) {
        cout << "Critical pollution days for " << names[i] << ": ";
        bool found = false;
        for (int j = 0; j < days; j++) {
            if (data[i][j] > 150) {
                cout << j + 1 << " ";
                found = true;
            }
        }
        if (!found) cout << "None";
        cout << endl;
    }
}

void visualizeAQI(float data[][28], string names[], int cities, int days) {
    cout << "AQI Visualization:" << endl;
    for (int i = 0; i < cities; i++) {
        cout << names[i] << ": ";
        for (int j = 0; j < days; j++) {
            int stars = data[i][j] / 50;
            for (int k = 0; k < stars; k++) cout << "*";
            cout << " ";
        }
        cout << endl;
    }
}

void monthlyAQIComparison(float data[][28], string names[], int cities) {
    float weeklyAvg[4][4], monthlyAvg[4], minImprovement = 99999;
    int improvedCity = -1;
    
    for (int i = 0; i < cities; i++) {
        float totalSum = 0;
        for (int w = 0; w < 4; w++) {
            float weekSum = 0;
            for (int j = w * 7; j < (w + 1) * 7; j++) weekSum += data[i][j];
            weeklyAvg[i][w] = weekSum / 7;
            totalSum += weeklyAvg[i][w];
        }
        monthlyAvg[i] = totalSum / 4;
    }
    
    cout << "Monthly AQI Averages:" << endl;
    for (int i = 0; i < cities; i++) cout << names[i] << ": " << monthlyAvg[i] << endl;

    for (int i = 0; i < cities; i++) {
        float improvement = weeklyAvg[i][0] - weeklyAvg[i][3];
        if (improvement > minImprovement) {
            minImprovement = improvement;
            improvedCity = i;
        }
    }
    
    cout << "City with most improved air quality: " << names[improvedCity] << endl;
}

void generateReport(float data[][28], string names[], int cities) {
    cout << "\n--- AQI Report ---\n";
    calculateAQI(data, names, cities, 28);
    criticalPollutionDays(data, names, cities, 28);
    monthlyAQIComparison(data, names, cities);
}

int main() {
    string names[4];
    float data[4][28];

    for (int i = 0; i < 4; i++) {
        cout << "Enter city name " << i + 1 << ": ";
        cin >> names[i];
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 28; j++) {
            cout << "AQI for " << names[i] << " on day " << j + 1 << ": ";
            cin >> data[i][j];
        }

    calculateAQI(data, names, 4, 7);
    criticalPollutionDays(data, names, 4, 7);
    visualizeAQI(data, names, 4, 7);
    monthlyAQIComparison(data, names, 4);
    generateReport(data, names, 4);

    return 0;
}

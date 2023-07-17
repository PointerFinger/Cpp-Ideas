#include <iostream>
#include <ctime>
#include <random>
#include <future>

int main() {
    time_t start, end;
    double timeTaken;

    using namespace std;
    
    // Generate a random wait time between 1 and 5 seconds
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 5);
    int waitTime = dis(gen);

    // Create a future object to handle the input
    future<string> futureInput = async(launch::async, []() {
        string input;
        cin >> input;
        return input;
    });

    // Wait for the input for the specified time
    future_status status = futureInput.wait_for(chrono::seconds(waitTime));

    // Check if there is no input after the specified time
    if (status == future_status::timeout) {
        cout << "stop" << endl;
    } else {
        // Retrieve and print the input
        string input = futureInput.get();
        cout << "Input received: " << input << endl;
    }
    
    cout << "Click as fast as you can!" << endl;
    cout << "Press Enter to start...";
    cin.get();

    start = time(0);

    cout << "Click now!" << endl;
    cin.get();

    end = time(0);

    timeTaken = difftime(end, start);

    cout << "Time taken: " << timeTaken << " seconds" << endl;

    return 0;
}

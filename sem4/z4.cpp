#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

class Time {
private:
    int hours, minutes, seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24; // Считаем время в формате 24 часа
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    Time(const std::string& timeStr) {
        char colon;
        std::stringstream ss(timeStr);
        ss >> hours >> colon >> minutes >> colon >> seconds;
        normalize();
    }

    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& t) {
        out << std::setw(2) << std::setfill('0') << t.hours << ":"
            << std::setw(2) << std::setfill('0') << t.minutes << ":"
            << std::setw(2) << std::setfill('0') << t.seconds;
        return out;
    }

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
};

std::vector<Time> parseTimes(const std::string& input) {
    std::vector<Time> times;
    std::stringstream ss(input);
    std::string timeStr;

    while (ss >> timeStr) {
        times.emplace_back(Time(timeStr));
    }
    
    return times;
}

Time sumTimes(const std::vector<Time>& times) {
    Time totalTime;
    for (const auto& t : times) {
        totalTime = totalTime + t;
    }
    return totalTime;
}

int main() {
    std::vector<Time> times = parseTimes("11:20:05 05:45:30 22:10:45");
    times.emplace_back(Time("01:10:30"));
    
    Time total = sumTimes(times);
    std::cout << total << std::endl;

    return 0;
}

class Solution {
public:
    int maximumPopulation(std::vector<std::vector<int>>& logs) {
        // Year range is 1950 to 2050 (101 possible years)
        std::vector<int> year_delta(101, 0);

        for (const auto& log : logs) {
            int birth = log[0];
            int death = log[1];
            year_delta[birth - 1950]++;
            year_delta[death - 1950]--;
        }

        int max_population = 0;
        int max_year = 1950;
        int current_population = 0;

        for (int i = 0; i < 101; i++) {
            current_population += year_delta[i];

            if (current_population > max_population) {
                max_population = current_population;
                max_year = 1950 + i;
            }
        }

        return max_year;
    }
};
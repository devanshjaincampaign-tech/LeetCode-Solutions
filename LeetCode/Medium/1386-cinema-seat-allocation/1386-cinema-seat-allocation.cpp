class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map only rows that have reservations: row_number -> 10-element bool vector
        unordered_map<int, vector<bool>> seats;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // If row not present yet, initialize with 11 elements (1-indexed)
            if (seats.find(row) == seats.end()) {
                seats[row] = vector<bool>(11, false);
            }
            seats[row][col] = true;
        }

        // Rows with zero reservations fit 2 groups automatically
        int totalGroups = (n - seats.size()) * 2;

        // Apply your exact boolean logic on the reserved rows
        for (auto& [row, rowSeats] : seats) {
            bool leftAvailable   = !rowSeats[2] && !rowSeats[3] && !rowSeats[4] && !rowSeats[5];
            bool rightAvailable  = !rowSeats[6] && !rowSeats[7] && !rowSeats[8] && !rowSeats[9];
            bool middleAvailable = !rowSeats[4] && !rowSeats[5] && !rowSeats[6] && !rowSeats[7];

            if (leftAvailable) {
                rowSeats[2] = rowSeats[3] = rowSeats[4] = rowSeats[5] = true;
                totalGroups++;
            }

            if (rightAvailable) {
                rowSeats[6] = rowSeats[7] = rowSeats[8] = rowSeats[9] = true;
                totalGroups++;
            }

            if (!leftAvailable && !rightAvailable && middleAvailable) {
                rowSeats[4] = rowSeats[5] = rowSeats[6] = rowSeats[7] = true;
                totalGroups++;
            }
        }

        return totalGroups;
    }
};
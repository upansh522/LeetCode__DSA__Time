class Solution {
public:
    // Function to convert decimal to binary and store it in a vector
    void decToBinary(int n, vector<int> &v) // Pass vector by reference
    {
        // Array to store binary number
        int binaryNum[32];

        // Counter for binary array
        int i = 0;
        while (n > 0) {
            // Storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        // Storing binary array in reverse order in vector
        for (int j = i - 1; j >= 0; j--)
            v.push_back(binaryNum[j]);
    }

    // Function to calculate minimum bit flips
    int minBitFlips(int start, int goal) {
        vector<int> st, gl;

        // Convert start and goal to binary
        decToBinary(start, st);
        decToBinary(goal, gl);

        // Make both vectors the same size by padding with leading zeros
        while (st.size() > gl.size()) {
            gl.insert(gl.begin(), 0);
        }
        while (gl.size() > st.size()) {
            st.insert(st.begin(), 0);
        }

        int cnt = 0;
        int n = gl.size();

        // Count how many bits differ between the two binary numbers
        for (int i = 0; i < n; i++) {
            if ((gl[i] ^ st[i]) == 1) // XOR to compare bits
                cnt++;
        }

        return cnt;
    }
};

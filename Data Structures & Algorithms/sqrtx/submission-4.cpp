class Solution {
public:
    int mySqrt(int x) {
        int left{0};
        int right{x};

        while (left <= right)
        {
            int mid{left + (right - left)/2};
            long long square{static_cast<long long>(mid) * mid};

            if (x == square) {
                return mid;
            }

            if (x > square)
            {
                left = mid + 1;
            }

            else
            {
                right = mid - 1;
            }
        }

        return right;
    }
};
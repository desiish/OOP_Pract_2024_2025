#include <iostream>
long long isNPart(long long n, long long k) {
    if (n == 0) {
        return 0;
    }
    if (n % 10 == k) {
        return 1;
    }
       return isNPart(n/10, k);

}
int main()
{
    long long n, k;
    std::cout << "Enter numbers n and k: \n";
    std::cin >> n >> k;
    std::cout << isNPart(n,k);
}


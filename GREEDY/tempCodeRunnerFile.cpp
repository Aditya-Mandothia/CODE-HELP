
int main()
{
    // Given input
    vector<int> people = {4, 3, 5, 6, 10};
    vector<int> starting = {1, 2, 3, 6, 5};
    vector<int> ending = {1, 2, 5, 7, 7};
    int N = people.size();

    // Find the minimum number of people that cannot meet
    int result = solve(N, people, starting, ending);

    // Output the result
    cout << "Minimum number of people that cannot meet: " << result << endl;

    return 0;
}

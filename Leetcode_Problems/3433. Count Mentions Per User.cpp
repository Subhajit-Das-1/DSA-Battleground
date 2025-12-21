// You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

// Each events[i] can be either of the following two types:

// Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
// This event indicates that a set of users was mentioned in a message at timestampi.
// The mentions_stringi string can contain one of the following tokens:
// id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
// ALL: mentions all users.
// HERE: mentions all online users.
// Offline Event: ["OFFLINE", "timestampi", "idi"]
// This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
// Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

// All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

// Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

 

// Example 1:

// Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]

// Output: [2,2]

// Explanation:

// Initially, all users are online.

// At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

// At timestamp 11, id0 goes offline.

// At timestamp 71, id0 comes back online and "HERE" is mentioned. mentions = [2,2]

// Example 2:

// Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]

// Output: [2,2]

// Explanation:

// Initially, all users are online.

// At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

// At timestamp 11, id0 goes offline.

// At timestamp 12, "ALL" is mentioned. This includes offline users, so both id0 and id1 are mentioned. mentions = [2,2]

// Example 3:

// Input: numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]

// Output: [0,1]

// Explanation:

// Initially, all users are online.

// At timestamp 10, id0 goes offline.

// At timestamp 12, "HERE" is mentioned. Because id0 is still offline, they will not be mentioned. mentions = [0,1]

 

// Constraints:

// 1 <= numberOfUsers <= 100
// 1 <= events.length <= 100
// events[i].length == 3
// events[i][0] will be one of MESSAGE or OFFLINE.
// 1 <= int(events[i][1]) <= 105
// The number of id<number> mentions in any "MESSAGE" event is between 1 and 100.
// 0 <= <number> <= numberOfUsers - 1
// It is guaranteed that the user id referenced in the OFFLINE event is online at the time the event occurs.

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        struct E {
            string type;    // "MESSAGE", "OFFLINE", "ONLINE"
            int t;
            string payload; // for MESSAGE: mentions_string, for OFFLINE/ONLINE: user id as string
        };

        vector<E> all;
        all.reserve(events.size() * 2);

        for (auto &ev : events) {
            string kind = ev[0];
            int t = stoi(ev[1]);
            string payload = ev[2];
            if (kind == "OFFLINE") {
                all.push_back({ "OFFLINE", t, payload });
                all.push_back({ "ONLINE", t + 60, payload }); // schedule return
            } else { // MESSAGE
                all.push_back({ "MESSAGE", t, payload });
            }
        }

        auto typeRank = [&](const string &s)->int {
            if (s == "ONLINE") return 0;   // process comes-back-online first
            if (s == "OFFLINE") return 1;  // then go-offline
            return 2;                      // then messages
        };

        sort(all.begin(), all.end(), [&](const E &a, const E &b){
            if (a.t != b.t) return a.t < b.t;
            int ra = typeRank(a.type), rb = typeRank(b.type);
            if (ra != rb) return ra < rb;
            // keep deterministic tie-breaker
            if (a.type != b.type) return a.type < b.type;
            return a.payload < b.payload;
        });

        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);

        for (auto &e : all) {
            if (e.type == "OFFLINE") {
                int id = stoi(e.payload);
                online[id] = false;
            } else if (e.type == "ONLINE") {
                int id = stoi(e.payload);
                online[id] = true;
            } else { // MESSAGE
                const string &s = e.payload;
                if (s == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) mentions[i] += 1;
                } else if (s == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i)
                        if (online[i]) mentions[i] += 1;
                } else {
                    stringstream ss(s);
                    string token;
                    while (ss >> token) {
                        if (token.size() >= 3 && token.rfind("id", 0) == 0) {
                            int id = stoi(token.substr(2));
                            mentions[id] += 1;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};
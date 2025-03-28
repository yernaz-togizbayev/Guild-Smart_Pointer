# 🧠 Guild Management Simulation – Programming 2 Project

This project simulates a licensing and guild system using C++ and is designed to reinforce key concepts from the **Programming 2** university course. The primary focus is on **smart pointers**, **object-oriented design**, and safe memory management.

---

## 📚 Course Context

**Course**: Programming 2  
**Focus Areas**:
- `std::unique_ptr` and `std::shared_ptr`
- Dynamic memory management without leaks
- Class inheritance and polymorphism
- Exception safety
- Operator overloading and STL containers

---

## 🗂️ Project Structure

| File            | Description |
|-----------------|-------------|
| `main.cpp`      | Unit tests using Catch2 to test the `License` class. |
| `license.h/cpp` | Defines the `License` class with usage limits, salary info, and print functionality. |
| `person.h/cpp`  | Defines `Person` (abstract base class) and its subclasses: `Worker`, `Superworker`, and `SometimesMotivatedWorker`. |
| `guild.h/cpp`   | Defines `Guild` and `OpenGuild`, which manage members, licensing, and job offers. |

---

## 🚀 Key Concepts Demonstrated

- ✅ Use of `std::unique_ptr` for exclusive ownership (e.g., licenses)
- ✅ Use of `std::shared_ptr` for shared ownership (e.g., people in guilds)
- ✅ Class inheritance and overriding (`virtual` methods)
- ✅ Exception handling with `std::runtime_error`
- ✅ STL maps, vectors, and custom iterators
- ✅ Clean object lifetime management and zero memory leaks

---

## 🔍 How It Works

- **People** can receive licenses from **Guilds** by paying a fee.
- Licenses can be used up to 3 times; after that, they're invalid.
- People can work for guilds if they have valid licenses, earning a salary.
- Guilds manage their members and can grant licenses or offer jobs.
- Different types of workers (normal, super, sometimes motivated) have unique earning behavior.

---

## 🧪 Unit Tests

Includes tests (in `main.cpp`) using [Catch2](https://github.com/catchorg/Catch2):

```bash
g++ -std=c++17 -Wall -Wextra -o test_exec main.cpp license.cpp -I<catch2_include_path>
./test_exec
```

## Tests include:
- License creation and exceptions
- License validity and usage
- License printing
- Behavior edge cases

## Example Use
```cpp
int main() {
    auto bob = make_shared<Worker>("Bob", 150);
    Guild blacksmiths("Blacksmiths", 50, 500);
    blacksmiths.add_member(bob);
    blacksmiths.grant_license("Bob");

    if (bob->eligible("Blacksmiths")) {
        blacksmiths.offer_job(bob);
        cout << *bob << endl;
    }
}
```

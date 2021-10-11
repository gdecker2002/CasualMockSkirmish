#include "warrior/dragon.h"
#include "warrior/dwarf.h"
#include "warrior/goblin.h"
#include "warrior/grunt.h"
#include "warrior/knight.h"
#include "warrior/mammoth.h"
#include "warrior/ogre.h"
#include "warrior/sorcerer.h"
#include "warrior/troll.h"
#include "warrior/wolf.h"

#include "print.h"
#include "skirmish.h"
#include "user_input.h"

#include <string>
#include <ctime>
#include <vector>

static void print_title(void);
static void print_scenario(std::string optionNumber, std::string teamRed, std::string teamBlue);
static void print_quit(void);

int main() {
    // Set new random seed for each compile time.
    srand(static_cast<unsigned int>(time(nullptr)));

    // Print title.
    print_title();
    print();

    // Initialize choice input.
    unsigned int choice = 0;

    do {
        // Print scenario and quit options.
        print_scenario("1", "1 grunt", "1 grunt");
        print_scenario("2", "2 grunts", "2 grunts");
        print_scenario("3", "4 goblins", "2 dwarves");
        print_scenario("4", "5 ogres", "9 trolls");
        print_scenario("5", "1 dragon", "13 dwarves");
        print_scenario("6", "1 dwarf + 1 grunt + 1 troll", "1 goblin + 1 ogre");
        print_scenario("7", "5 knights", "3 wolves");
        print_scenario("8", "1 mammoth", "2 dragons");
        print_scenario("9", "4 sorcerers", "2 knights + 1 wolf");
        print_quit();
        print();

        std::vector<Warrior *> team_red;
		std::vector<Warrior *> team_blue;

        // Determine option selected.
        switch (choice = get_option(10)) {
            case 1: { // 1 grunt vs 1 grunt
                // Initialize each team.
                team_red  = { new Grunt("Billy") };
                team_blue = { new Grunt("Tasha") };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
				break;
            } case 2: { // 2 grunts vs 2 grunts
                // Initialize two grunts for each team
                team_red  = {
                    new Grunt("Billy"),
                    new Grunt("Tasha")
                };
                team_blue = {
                    new Grunt("Sam"),
                    new Grunt("Bessie")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 3: { // 4 goblins vs 2 dwarves
                // Initialize 4 goblins for team red
                team_red = {
                    new Goblin("Azog"),
                    new Goblin("Bolg"),
                    new Goblin("Golfimbul"),
                    new Goblin("Yazneg")
                };
                team_blue = { // And 2 dwarves for team blue
                    new Dwarf("Bifur"),
                    new Dwarf("Bofur")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 4: { // 5 ogres vs 9 trolls
                // Initialize 5 ogres for team red.
                team_red  = {
                    new Ogre("Dozug"),
                    new Ogre("Grizikur"),
                    new Ogre("Iuzug"),
                    new Ogre("Glezakag"),
                    new Ogre("Krezar")
                };
                // Initialize 9 trolls for team blue.
                team_blue = {
                    new Troll("Tom"),
                    new Troll("Bert"),
                    new Troll("William"),
                    new Troll("Torog"),
                    new Troll("Rogash"),
                    new Troll("Dingal"),
                    new Troll("Bill"),
                    new Troll("Ronald"),
                    new Troll("Bolmug")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 5: { // 1 dragon vs 13 dwarves
                // Initialize each team.
                team_red  = { new Dragon("Smaug") };
				// 13 dwarves for team blue.
                team_blue = {
                    new Dwarf("Dwalin"),
                    new Dwarf("Balin"),
                    new Dwarf("Kili"),
                    new Dwarf("Fili"),
                    new Dwarf("Dori"),
                    new Dwarf("Nori"),
                    new Dwarf("Ori"),
                    new Dwarf("Oin"),
                    new Dwarf("Gloin"),
                    new Dwarf("Bifur"),
                    new Dwarf("Bofur"),
                    new Dwarf("Bombur"),
                    new Dwarf("Thorin")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 6: { // 1 dwarf + 1 grunt + 1 troll vs 1 goblin + 1 ogre
                // Dwarf, grunt, and troll for team red.
                team_red  = {
                    new Dwarf("Thorin"),
                    new Grunt("Bilbo"),
                    new Troll("Bruz")
                };
                // Goblin and ogre for team blue.
                team_blue = { new Goblin("Grinnah"), new Ogre("Ozoc") };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 7: { // 5 knights vs 3 wolves
                // Initialize 5 knights for team red.
                team_red  = {
                    new Knight("Peregrin"),
                    new Knight("Elessar"),
                    new Knight("Aragorn"),
                    new Knight("Hakon"),
                    new Knight("Emund")
                };
                // 3 wolves for team blue.
                team_blue = {
                    new Wolf("Harog"),
                    new Wolf("Harach"),
                    new Wolf("Ulku")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 8: { // 1 mammoth vs 2 dragons
                // Initialize each team.
                team_red  = { new Mammoth("Mumak") };
                team_blue = { new Dragon("Scatha"), new Dragon("Gostir") };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 9: { // 4 sorcerers vs 2 knights + 1 wolf
                // Initialize 4 sorcerers for team red.
                team_red  = {
                    new Sorcerer("Merlin"),
                    new Sorcerer("Nicolas"),
                    new Sorcerer("Durion"),
                    new Sorcerer("Cassandra")
                };
                // 2 knights and 1 wolf for team blue.
                team_blue = {
                    new Knight("Peregrin"),
                    new Knight("Elessar"),
                    new Wolf("Harog")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } default: {
                // End game.
                print();
                print("Bye.");
                break;
            }
        }
    } while (choice < 10);

    // Exit program successfully.
    return 0;
}

/**
 * @brief print_title prints title header of simulation game.
 */

static void print_title(void) {
    print("************************", MAGENTA);
    print("* ", MAGENTA, false);
    print("Casual Mock Skirmish", DARK_RED, false);
    print(" *", MAGENTA);
    print("************************", MAGENTA);
}

/**
 * @brief print_scenario prints scenario option.
 * @param optionNumber = string of option number
 * @param teamRed = team red warriors
 * @param teamBlue = team blue warriors
 */

static void print_scenario(std::string optionNumber, std::string teamRed, std::string teamBlue) {
    print(optionNumber, CYAN, false);
    print(" - ", DARK_WHITE, false);
    print(teamRed, RED, false);
    print(" vs ", DARK_WHITE, false);
    print(teamBlue, BLUE);
}

/**
 * @brief print_quit prints quit option.
 */

static void print_quit(void) {
    print("10", YELLOW, false);
    print(" - ", DARK_WHITE, false);
    print("Quit", MAGENTA);
}


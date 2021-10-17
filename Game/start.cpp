//==================================
// Casual Mock Skirmish
//----------------------------------
// Class: CIS-164 Advanced C++
//----------------------------------
// Reckless Alliance (Contributors):
//     - Noah Allan Ertz
//     - Tanner Babcock
//     - Owen Miner
//     - Lukas Lawler
//     - Gage Decker
//     - Jeffrey Garretto
//----------------------------------
// License: AGPL-3.0
//----------------------------------
// 2021
//==================================

#include "print.h"
#include "skirmish.h"
#include "user_input.h"

#include "warrior/bandit.h"
#include "warrior/basilisk.h"
#include "warrior/dragon.h"
#include "warrior/dwarf.h"
#include "warrior/ghost.h"
#include "warrior/goblin.h"
#include "warrior/grunt.h"
#include "warrior/knight.h"
#include "warrior/mammoth.h"
#include "warrior/ogre.h"
#include "warrior/serpent.h"
#include "warrior/snowman.h"
#include "warrior/sorcerer.h"
#include "warrior/troll.h"
#include "warrior/witch.h"
#include "warrior/wolf.h"

#include <string>
#include <ctime>
#include <vector>

static void print_title(void);
static void print_scenario(std::string optionNumber, std::string teamRed, std::string teamBlue);
static void print_quit(void);

int main(void) {
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
        print_scenario("4", "1 ogres", "7 trolls");
        print_scenario("5", "1 dragon", "13 dwarves");
        print_scenario("6", "5 dwarves + 4 grunts + 2 trolls", "1 goblin + 1 ogre");
        print_scenario("7", "1 knight", "7 wolves");
        print_scenario("8", "1 mammoth", "2 dragons");
        print_scenario("9", "4 sorcerers", "2 knights + 1 wolf");
        print_scenario("10", "1 ghost", "8 witches");
        print_scenario("11", "9 snowmen", "3 bandits");
        print_scenario("12", "1 serpent + 3 snowmen + 1 ghost", "1 basilisk");
        print_scenario("13", "3 snowmen + 1 ogre + 1 grunt", "2 ghosts + 2 sorcerers + 1 grunt");
        print_scenario("14", "1 wolf + 1 bandit", "1 goblin + 2 snowmen");
        print_quit();
        print();

        std::vector<Warrior*> team_red;
        std::vector<Warrior*> team_blue;

        // Determine option selected.
        switch (choice = get_option(15)) {
            case 1: { // 1 grunt vs 1 grunt
                // Initialize 1 grunt for team red.
                team_red  = {
                    new Grunt("Billy")
                };

                // Initialize 1 grunt for team blue.
                team_blue = {
                    new Grunt("Tasha")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
				break;
            } case 2: { // 2 grunts vs 2 grunts
                // Initialize 2 grunts for team red.
                team_red  = {
                    new Grunt("Billy"),
                    new Grunt("Tasha")
                };

                // Initialize 2 grunts for team blue.
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
                // Initialize 4 goblins for team red.
                team_red = {
                    new Goblin("Azog"),
                    new Goblin("Bolg"),
                    new Goblin("Golfimbul"),
                    new Goblin("Yazneg")
                };

                // Initialize 2 dwarves for team blue.
                team_blue = {
                    new Dwarf("Bifur"),
                    new Dwarf("Bofur")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 4: { // 1 ogres vs 7 trolls
                // Initialize 1 ogre for team red.
                team_red  = {
                    new Ogre("Dozug")
                };

                // Initialize 7 trolls for team blue.
                team_blue = {
                    new Troll("Tom"),
                    new Troll("Bert"),
                    new Troll("William"),
                    new Troll("Torog"),
                    new Troll("Rogash"),
                    new Troll("Dingal"),
                    new Troll("Bill")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 5: { // 1 dragon vs 13 dwarves
                // Initialize 1 dragon for team red.
                team_red  = {
                    new Dragon("Smaug")
                };

                // Initialize 13 dwarves for team blue.
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
            } case 6: { // 5 dwarf + 4 grunt + 2 troll vs 1 goblin + 1 ogre
                // Initialize 5 dwarves, 4 grunts, and 2 trolls for team red.
                team_red  = {
                    new Dwarf("Thorin"),
                    new Dwarf("Redbeard"),
                    new Dwarf("Dorin"),
                    new Dwarf("Dwurf"),
                    new Dwarf("Murf"),
                    new Grunt("Bilbo"),
                    new Grunt("Gollum"),
                    new Grunt("Smeagol"),
                    new Grunt("Bigfoot"),
                    new Troll("Bruz"),
                    new Troll("Truz")
                };

                // Initialize 1 goblin and 1 ogre for team blue.
                team_blue = { new Goblin("Grinnah"), new Ogre("Ozoc") };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 7: { // 1 knight vs 7 wolves
                // Initialize 1 knight for team red.
                team_red  = {
                    new Knight("Peregrin")
                };

                // Initialize 7 wolves for team blue.
                team_blue = {
                    new Wolf("Harog"),
                    new Wolf("Harach"),
                    new Wolf("Ulku"),
                    new Wolf("Bandi"),
                    new Wolf("Pooch"),
                    new Wolf("Ukwu"),
                    new Wolf("Pamalam")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
            } case 8: { // 1 mammoth vs 2 dragons
                // Initialize 1 mammoth for team red.
                team_red  = {
                    new Mammoth("Mumak")
                };

                // Initialize 2 dragons for team blue.
                team_blue = {
                    new Dragon("Scatha"),
                    new Dragon("Gostir")
                };

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

                // Initialize 2 knights and 1 wolf for team blue.
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
           } case 10: { // 1 ghost vs 8 witches
                // Initialize 1 ghost for team red.
                team_red  = {
                    new Ghost("Casper")
                };

                // Initialize 8 witches for team blue.
                team_blue = {
                    new Witch("Glenda"),
                    new Witch("Snaggletooth"),
                    new Witch("Nosewart"),
                    new Witch("Circe"),
                    new Witch("Blair"),
                    new Witch("Hecate"),
                    new Witch("Morgan le Fay"),
                    new Witch("Nimue")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
           } case 11: { // 9 snowmen vs 3 bandits
                // Initialize 9 snowmen for team red.
                team_red  = {
                    new Snowman("Tim"),
                    new Snowman("Angel Mcslushie"),
                    new Snowman("Hot Head Alan"),
                    new Snowman("Jimmy No Nose"),
                    new Snowman("Timmy knows Jimmy No Nose"),
                    new Snowman("Frosty"),
                    new Snowman("Frosty's Cousin Slushie"),
                    new Snowman("Melty"),
                    new Snowman("Melvin No Buttons")
                };

                // Initialize 3 bandits for team blue.
                team_blue = {
                    new Bandit("Scary Terry"),
                    new Bandit("Mischief Mike"),
                    new Bandit("Burglar Barry")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
          } case 12: { // 3 snowmen + 1 serpent + 1 ghost vs 1 basilisk
                // Initialize 3 snowmen, 1 serpent, and 1 ghost for team red.
                team_red  = {
                    new Snowman("Tim"),
                    new Snowman("Angel Mcslushie"),
                    new Snowman("Hot Head Alan"),
                    new Serpent("Rattles"),
                    new Ghost("Casper")
                };

                // Initialize 1 basilisk for team blue.
                team_blue = {
                    new Basilisk("Zaccasash")
                };

                // Start skirmish simulation.
                print();
                start_skirmish(team_red, team_blue);
                print();
                break;
        } case 13: { // 3 snowmen + 1 ogre + 1 grunt vs 2 ghost + 2 sorcerer + 1 grunt
            // Initialize 3 snowmen, 1 ogre, and 1 grunt for team red.
            team_red = {
                new Snowman("Melter Skelter"),
                new Snowman("Quizsnows"),
                new Snowman("Icy Stars"),
                new Ogre("Blurek"),
                new Grunt("Glik")
            };

            // Initialize 2 ghosts, 2 sorcerers, and 1 grunt for team blue.
            team_blue = {
                new Ghost("Scary Gary"),
                new Ghost("Slimer"),
                new Sorcerer("Bimble"),
                new Sorcerer("Yerdott"),
                new Grunt("Ungor")
            };

            // Start skirmish simulation.
            print();
            start_skirmish(team_red, team_blue);
            print();
            break;
        } case 14: { // 1 wolf + 1 bandit vs 1 goblin + 2 snowmen
            // Initialize 1 wolf and 1 bandit for team red.
            team_red = {
                new Wolf("Doggo"),
                new Bandit("Buster")
            };

            // Initialize 1 goblin and 2 snowmen for team blue.
            team_blue = {
                new Goblin("Irk"),
                new Snowman("The Cold One"),
                new Snowman("Mr. Freeze")
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
    } while (choice < 15);

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
    print("15", YELLOW, false);
    print(" - ", DARK_WHITE, false);
    print("Quit", MAGENTA);
}

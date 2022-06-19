#define LINE cout << "-------------------------\n" << endl; //You can type in "LINE" whenever you want to add a separating line between texts now
#define INV else if(action==0){ void runtime(); } //Work on this sometime, or another function, to give the player the option of opening inventory whenever

#include <iostream>//For basically everything, mainly the cout and cin stuff
#include <ctime>//For the random number thingies but the new cstdlib takes care of that as well
#include <vector>//For inventory stuff
#include "Items.h"
#include "Spells.h"
#include <algorithm>//Sorting thru vectors (inventories, etc.)
#include "Catanada.h"
#include "PlayerData.h"



using namespace std;

int playerdamage;

int dieTwenty();
int dieTen();
int orc();
int dieTwenty1();
int goblin();
int ruins();
int trading();
int inn();
int inn_chat();
int gettingstarted();
void runtime();
int morning();


int goblin() {
	cout << "Walking down the dark forest, you encounter a goblin!" << endl;
	cout << "What do you do?" << endl;
	cout << "1. Attack" << endl;
	cout << "2. Speak" << endl;
	cout << "3. Flee" << endl;
	cout << "------------------------------------" << endl;
	cin >> action;

	if (action == 1) {
		cout << "You attack the goblin and thrust your sword into it to deal " << playerdamage << " damage!" << endl;
		cout << "The goblin slashes your arm with its sword, dealing " << dieTen() << " damage to you." << endl;
		cout << "You attack it again, and kill it!" << endl;
		cout << "Press 4 to loot it, 5 to keep walking." << endl;
		cin >> action;
		if (action == 4) {
			cout << "The goblin has a pouch containing 10 gold!" << endl;
			gold = gold + 10;
			cout << "Total gold:" << gold << endl;
			cout << "------------------------------------" << endl;

			return orc();
			return 0;
		}

		else if (action == 5) {
			cout << "You continue your journey..." << endl;
			cout << "------------------------------------" << endl;

			return ruins(); 
		}
	}
	else if (action == 2) {
		cout << "The goblin looks at you and says, 'Ah, another traveler. What are you here for?'" << endl;
		cout << "1. Not much, though I'd love to get something new. Got anything interesting?" << endl;
		cout << "2. Just taking a walk on this nice day." << endl;
		cout << "3. None of your business." << endl;
		cout << "4. Here for all the gold!" << endl;
		cout << "------------------------------------" << endl;
		cin >> action;

		if (action == 1) {
			cout << "The goblin takes out a necklace adorned with what appears to be a dragon tooth. 'Like it? 25 gold. I don't negotiate.'" << endl;
			cout << "What do you say?" << endl;
			cout << "1. Yeah, sure, nice thing." << endl;
			cout << "2. What a scam." << endl;
			cin >> action;

			if (action == 1) {
				items dragon_necklace{ 50, 2, "Dragon Necklace\n", "A necklace with the tooth of a dragon at one end, bought from a goblin on your way to the Ruins." };
				inventory.push_back(dragon_necklace);
				cout << "You give 30 gold. The goblin looks at them, nods, and hands the necklace. 'Shiny enough.' it says." << endl;
				for (const auto& curr : inventory) {
					cout << "------------------------------------\n";
					cout << "Your inventory:" << endl;
					cout << curr.getInv();
					cout << "------------------------------------\n";
				}
				gold = gold - 25;
				cout << "Total gold:" << gold << endl;
				cout << "------------------------------------" << endl;

				return orc();
				return 4;
			}

			else if(action == 2) {
				cout << "The goblin looks angry and pokes his sword to you for " << dieTen() << " damage." << endl;
				cout << "You run away far from the goblin. 'Your mom's a scam, idiot!' it shouts." << endl;
				hp = hp - dieTen();
				cout << "Total HP:" << hp  << endl;
				cout << "------------------------------------" << endl;
				
				return ruins();
			}
		}

		else if (action == 2) {
			cout << "'Pass by then, I don't want no trouble.' the goblin says." << endl;
			cout << "You walk by off on your path." << endl;
			cout << "------------------------------------" << endl;

			return ruins();
		}

		else if (action == 3) {
			cout << "'Well, I might as well be yours then, bitch.!' the goblin says. You draw your sword, slash it and deal " << dieTwenty() << " damage." << endl;
			cout << "The goblin punches you in the face for " << dieTen() << " damage. It's not gonna look nice tomorrow." << endl;
			hp = hp - dieTen();
			cout << "Total HP:" << hp << endl;
			cout << "You spit on the ground and go away from this uncivilized creature." << endl;
			cout << "------------------------------------" << endl;

			return orc();
		}
		
		else if (action == 4) {
			cout << "The goblin laughs. 'Can relate. You off to the Ruins as well?' You nod. 'I'll come with you then. Nice meeting you,...?" << endl;
			cout << name << ", you say. The goblin nods and follows you on your path to the Ruins." << endl;
			cout << "------------------------------------" << endl;

			return orc();
			return 10;
			
		}
	}

	else if (action == 3) {
		cout << "The goblin says, 'Eyo, traveller, leave some gold to I, the one who controls the way!' What do you do?" << endl;
		cout << "1. Throw some of your gold and run away." << endl;
		cout << "2. Keep your gold and life - just dash off." << endl;
		cout << "------------------------------------" << endl;
		cin >> action;

		if (action == 1) {
			cout << "You grab your pouch, throw " << dieTwenty1() << " gold to the goblin and run away while it examines that gold." << endl;
			gold = gold - dieTwenty1();
			cout << "Total gold:" << gold << endl;
			cout << "------------------------------------" << endl;

			return ruins();
		}

		else if (action == 2) {
			cout << "You start running away as fast as you can but still get hit by the dagger sent flying goblin. You take " << dieTen() << " damage." << endl;
			hp = hp - dieTen();
			cout << "Total HP:" << hp << endl;
			cout << "------------------------------------" << endl;

			return orc();
			return 0;
		}
		return 0;
	}
	return 0;
}

int orc() {
	cout << "Going down your path to the Ruins, you stumble upon a lit campfire. A dead human is being cooked on top of it. What will you do?" << endl;
	cout << "1. mmmmm, free food!" << endl;
	cout << "2. Let the person be, with their disgusting habits." << endl;
	cout << "3. I'm gonna wait to see who comes back here." << endl;
	
	cout << "------------------------------------" << endl;
	cin >> action;

	if (action == 1) {
		cout << "You take down the half-cooked human and look at it to find a part to eat. Managing to cut some piece off of him, you eat the salty meat - ewwww." << endl;
		cout << "------------------------------------" << endl;
		
		return ruins();
	}

	else if (action == 2) {
		cout << "You walk away on your path and eat an apple on a tree instead." << endl;
		cout << "------------------------------------" << endl;

		return ruins();
	}

	else if (action == 3) {
		cout << "Nothing happens before the sky darkens and you wait while the human gets cooked up. Then, a terrifying orc shows up from the woods - it doesn't look quite happy to see you!" << endl;
		cout << "1. Fight it." << endl;
		cout << "2. Run!" << endl;
		cin >> action;

		if (action == 1) {
			cout << "You throw a stick to distract the orc and stab him in the chest - " << dieTwenty() << " damage." << endl;
			cout << "The orc groans and swings its club at you, dealing a solid " << dieTen() << " damage." << endl;
			cout << "You swing your sword again for " << dieTwenty() << " damage." << endl;
			cout << "The orc tries to charge you but you manage to sidestep it and it steps on the fire, taking " << dieTwenty1() << " damage." << endl;
			cout << "You take advantage of this and swing your sword overhead, managing to chop its head off!" << endl;
			hp = hp - dieTen();
			cout << "Total HP:" << hp << endl;
			cout << "------------------------------------" << endl;
			cout << "4. Loot the body.\n" << endl;
			cout << "5. Keep walking.\n" << endl;
			cin >> action;
			
			if (action == 4) {
				items redgem{ 100, 4, "Red Gem\n" };
				inventory.push_back(redgem);
				cout << "The orc has a gem in a pouch that was tied to its waist. The gem is worth 100 gold!" << endl;
				cout << "Your inventory:" << endl;
				for (const auto& curr : inventory) {
				
					cout << curr.getInv();

				}
				cout << "You continue your journey to the Ruins, now with the red gem contained in your pouch." << endl;
				cout << "------------------------------------" << endl;

				return ruins();
 			}

			else if (action == 5) {
				cout << "You continue your journey to the Ruins, trusting what you already have in your pouch of gold." << endl;
				cout << "------------------------------------" << endl;
				return ruins();
			}
			return 0;
		}

		else if (action == 2) {
			cout << "You run away while the orc groans and shouts and tries throwing sticks at you, but you get away without harm - best to get to the Ruins as soon as possible." << endl;
			cout << "------------------------------------" << endl;
			return ruins();
		}
	}

	
	return 0;
}

int ruins() {
	cout << "You arrive at the Ruins, the infamous remnants of the past town that had been annihilated by the orc raids and eventually, the erupting volcano.\n";
	cout << "There seems to be a bunch of people talking by, and some of the patched-up ruins seem to have torches lit up inside - some people must've moved in now...\n";
	cout << "What do you want to do?\n";
	cout << "1. Talk to the people and see what's cooking around here." << endl;
	cout << "2. I need a drink." << endl;
	cout << "3. I want to talk to someone who's moved in here." << endl;
	cout << "------------------------------------" << endl;
	cin >> action;

	if (action == 1) {
		cout << "You approach the small clump of people. A man tells a bunch of travellers of the 'horrors I've seen last night' while some people in dark robes discuss something in whispers.";
		cout << "A couple of men and women show each other some maps and various items, some talking about which places might contain good loot and the others try trading what they've found in some dungeon or the like." << endl;
		cout << "1. Listen to and maybe talk to the man telling the horrors." << endl;
		cout << "2. See what the dark robed people are talking about - they might have useful information." << endl;
		cout << "3. Chat with the folk talking about adventuring." << endl;
		cout << "4. Love me some good trading." << endl;
		cout << "------------------------------------" << endl;
		cin >> action;

		if (action == 1) {
			cout << "The man talks of a gigantic beast, larger than a polybear, with flaming green eyes and tentacles coming from all around it. He ends his story by saying, 'And I knew I had to get out of there fast - and here I am. That shit ain't good news, people. Stay clear of the forest, I'd say.'";
			cout << "The people listening to him start talking to each other about whether or not the man was telling the truth or what that creature could be. You approach the man. 'Heyo, mate, what are you looking for around here?' He asks." << endl;
			cout << "1. Where exactly did you see that creature?" << endl;
			cout << "2. Got any other stories to tell?" << endl;
			cout << "3. You sure that wasn't some random-ass polybear standing right behind a bunch of trees? You know, I've seen a buncha those and it sounds similar." << endl;
			cout << "4. Need some food and a bed for the night. You know a good enough place 'round here?" << endl;
			cin >> action;

			if (action == 1) {
				cout << "The man points to the west of the town and says, 'Right there, deep into the forest, next to the little lake. That is exactly where you don't wanna go.'" << endl;
			}

			else if (action == 2) {
				cout << "The man laughs and says, 'Many - too much for just one night. If you wanna hear though, come to the Floating Inn at the other side of the town tomorrow morning and we can have a nice talk, alright?'" << endl;
			}

			else if (action == 3) {
				cout << "'Eyo, I've seen similar stuff too mate but this shit was something waaaaay weirder. If you don't believe me, you're free to go check it out yourself.'" << endl;
			}

			else if (action == 4) {
				cout << "The man points to the north. 'Riiight over there, at the other side of the town, is the Floating Inn. Herr is a nice guy - you won't have to pay much for a good night's stay.'" << endl;
			}
			return 0;
		}

		else if (action == 2) {
			cout << "As you take a few steps towards the dark robed figures, they stop talking and stare at you. One of the figures hisses 'What are you here for?'" << endl;
			cout << "1. New here and thought I could learn what's been going around in here." << endl;
			cout << "2. Wanted to join you guys - you guys seem to know what you're doing." << endl;
			cout << "3. Would be cool if you weren't this...suspicious of people." << endl;
			cout << "------------------------------------" << endl;
			cin >> action;

			if (action == 1) {
				cout << "The figure where the sound came from looks away. 'Not much good. I'd say get over the Ruins and live a happily ever after." << endl;
			}

			else if (action == 2) {
				cout << "'Nice joke.' the figure says and turns it face at the other figures. 'We aren't recruiting.'" << endl;
			}

			else if (action == 3) {
				cout << "The figure pushes you with surprising force for a human. 'Steer clear of us.'" << endl;
			}
		}

		else if (action == 3) {
			cout << "Four of the ten-ish people chatting seem to be an adventuring party and are telling others of their plans on going to the specter's lair soon.";
			cout << "The others are talking about the quests they saw in one of the large cities and also discussing how to see if a door is trapped or not - the popular opinion seems to be sticking a thin stick into the lock before kicking it open." << endl;
			cout << "Do you want to talk to the individuals or the party?" << endl;
			cout << "1. I'll talk to the party - they seem to be better organized." << endl;
			cout << "2. The individuals could be heplful and might find myself a partner as well." << endl;
			cout << "------------------------------------" << endl;
			cin >> action;

			if (action == 1) {
				cout << "The party consists of a young man, a middle-aged woman and two middle-aged men. The younger man takes notice of you. 'Heyy, what's up?' he says. The woman frowns at you and continues talking to the other two men. " << endl;
				cout << "1. Just checking out the Ruins - they seem quite different." << endl;
				cout << "2. Looking around for quests, know anything interesting here?" << endl;
				cout << "3. Checking the place around for folk to pursue stuff with - you guys want a fifth member?" << endl;
				cin >> action;

				if (action == 1) {
					cout << "The man nods while looking around. 'Yeah, feels weird. The last time I was here, it lived up to its name...can't tell whether or not the change is a good thing. If you want the news, though, go to the inn at the other side of town. It might be the place for you." << endl;
					cout << "------------------------------------" << endl;
					return inn();
				}

				else if (action == 2) {
					cout << "'Yeah - the old man Arger, the smith, was looking for someone to help him with some matter - his house is right there.' He points at a small house with orange light coming out of the windows." << endl;
					cout << "------------------------------------" << endl;
					//ADD IN THE SMITH ENCOUNTER HERE
				}

				else if (action == 3) {
					cout << "The man turns around and elbows one of the older men. He mumbles something to his ear and they look at you. After a couple minuted talking between themselves, the woman nods at you and says, 'We'll be off to the specter's lair in a couple days. Come then or never.'" << endl;
					cout << "------------------------------------" << endl;
					//ADD IN YES OR NO STUFF HERE
				}
			}
			
			else if (action == 2) {
				cout << "As you are standing around, a young girl holds a map in front of your face and asks, 'Tell me, don't you also see that hill is obviously the Living Hill?' Without waiting for your answer, she turns to the guy she's been arguing with and takes out another map to prove her point." << endl;
				cout << "1. Join in the conversation the boy and girl are having." << endl;
				cout << "2. Exchange with a bunch of other folk - maybe I'll find an adventuring partner here." << endl;
				cout << "------------------------------------" << endl;
				cin >> action;

				//ADD IN A BUNCH OF RESULTS FOR BOTH, TIE IN SECOND OPTION WITH EITHER THE BOSS FIGHT OR THE INN 
			}
		}

		else if (action == 4) {
			return trading();
		}


	}

	else if (action == 2) {
	cout << "After walking around for about fifteen minutes, you come across a large stone building with a sign that reads 'Floating Inn'. There's light coming out of the windows, and you enter the building." << endl;
	cout << "------------------------------------" << endl;
	return inn();
}

	else if (action == 3) {
	cout << "Walking around, you see around five or six houses with light coming from the inside - One has hammering sounds coming from the inside, the other appears to be a shop for goods, there's an inn, ";
	cout << "a place selling items for travelling and a small house converted into an arms shop." << endl;
	cout << "1. I'll go see the smith." << endl;
	cout << "2. Lemme check out if the goods shop has useful stuff." << endl;
	cout << "3. An inn sounds good - the sky's getting dark now." << endl;
	cout << "4. Some maps and maybe a bunch of clothes sounds good." << endl;
	cout << "5. Ooh, sharp stuff!" << endl;
	cout << "------------------------------------" << endl;
	cin >> action;

	if (action == 1) {
		//ADD IN SMITH ENCOUNTER
	}

	else if (action == 2) {
		//ADD IN STORE STUFF 
	}

	else if (action == 3) {
		return inn();
	}

	else if (action == 4) {
		//TRAVELLER'S SHOP ENCOUNTER
	}

	else if (action == 5) {

		//ARMS SHOP 
	}
}
	return 0;
}

int trading() {
	weapons clockwork_sword{ 100, 5, "Clockwork Sword", "A more reliable sword which deals less maximum damage but higher minimum damage.", 5 };
	items healing_potion{ 10,6,"Healing Potion", "A black liquid inside of a small bottle. Regenerates 5 HP when used."  };
	items flute{ 15,7,"Flute", "A light wooden pipe with holes across, perfect for entertaining folks." };
	map dungeon_map{ 30,8,"Dungeon Map", "Shows the location of a secretive dungeon which has the promise of more loot.", "A little hill that can be easily located nearby,", "some stones marked in a certain pattern and a hidden trapdoor among them" };
	spellbook basic_spellbook{ 150,9,"Spellbook", "A small, amateur-ish book containing three spells that you can cast at will using this book." }; //Try not to implement spells until later on or smth
	items secretive_box{ 0,10,"Secretive Box", "Nobody knows how to open this jet black box, or if it opens in the first place" };
	items eye_of_thraller{ 35,11,"Eye of the Thraller", "This eye off a dead Thraller lets you see through where it is for some time." };

	fireball fireball_spell{ "Fireball", "A rare spell of incredible destructive force with, obviously, fire.", 1 };
	frost frost_spell{ "Frost", "A spell to freeze one enemy stuck in ice.", 2 };
	light light_spell{ "Light", "A basic spell to create a ball of white light to follow you.",3 };

	basic_spellbook.spellsinside.push_back(fireball_spell);
	basic_spellbook.spellsinside.push_back(frost_spell);
	basic_spellbook.spellsinside.push_back(light_spell);


	std::vector <items> trades{ clockwork_sword,healing_potion,flute,dungeon_map,basic_spellbook,secretive_box,eye_of_thraller };

	cout << "You walk to the group of people exchanging various items: Glowing beads, glass rods, many eyes of multiple monsters and all other sorts of things." << endl;
	cout << "1. I wanna see if there's anything worth buying. " << endl;
	cout << "2. I think I can make some money by selling my stuff." << endl;
	cout << "------------------------------------" << endl;
	cin >> action;

	if (action == 1) {
		for (size_t index{}; index < trades.size(); index++)
		{
			std::cout << (index) << ')' << trades[index].itemname << " - " << trades[index].itemgold << " gold" << " - " << trades[index].description << '\n';
		}

		cout << "Type in the number of the item you want to buy." << endl;
		cin >> which_one;
		if (gold >= trades[which_one].itemgold) {
			cout << "You bought:" << trades[which_one].itemname << endl;
			gold = gold - trades[which_one].itemgold;
			cout << "Remaining gold:" << gold << endl;
			inventory.push_back(trades[which_one]);
		

			cout << "Do you want to keep trading or do something else?" << endl;
			cout << "1. I'll keep trading." << endl;
			cout << "2. I'll go to the inn and rest for now." << endl;
			cin >> action;

			if (action == 1) {
				return trading();
			}

			else if (action == 2) { 
				return inn(); 
			}

			else if (action == 3) {
				dungeon_map.getlocations();
			}
		}

		else if (gold < trades[which_one].itemgold) {
			cout << "You cannot afford this item!" << endl;
			cout << "Enter 1 to keep trading, 2 to go to the inn." << endl;
			cin >> action;

			if (action == 1) {
				return trading();
			}

			else if (action == 2) {
				return inn();
			}
		}
	}

	else if (action == 2) {
		if (inventory.size() > 0) {
			cout << "------------------------------------\n";
			cout << "Your inventory:" << endl;

			for (size_t index{}; index < inventory.size(); index++)
			{
				std::cout << (index) << ')' << inventory[index].itemname << '\n';
			}

			cout << "------------------------------------\n";
			cout << "Type in the number of the item you want to sell:" << endl;
			cin >> which_one;
			cout << "You got " << inventory[which_one].itemgold << " gold." << endl;
			gold = gold + inventory[which_one].itemgold;
			cout << "Total gold: " << gold << endl;
			inventory.erase((inventory.begin()));

			cout << "Enter 1 if you want to continue trading or 2 if you want to head to the inn." << endl;
			cin >> action;
			if (action == 1) {
				return trading();
			}

			else if (action == 2) {

				basic_spellbook.getspells();
				return inn();
			}
		}

		else if (inventory.size() <= 0) {
			cout << "You don't have any items to sell!" << endl;
			cout << "Press 1 if you want to keep trading, 2 if you want to go to the inn." << endl;
			cin >> action;
			if (action == 1) {
				return trading();
			}

			else if (action == 2) {
				return inn();
			}
		}
	}
	return 0;
}

int inn() {
	cout << "The inn Floating Tavern is an interesting building of three stories - the first one is made out of mostly the original ruins while the other two are newer, mainly wood. Inside,";
	cout << " a blue fire sits in the middle of the taproom and the innkeeper, Herr, welcomes you behind the clean wooden counter right on the opposite side of the floor. 'Come over,' he says with a smile. 'first ale's on me.'" << endl;
	cout << "You take the first ale and Herr looks around the room as you drink it, preparing a couple more mugs and leaving them on the counter for one of the customers to take." << endl;
	cout << "------------------------------------" << endl;
	cout << "'So, what kind of adventure are you here for?' he asks." << endl;
	cout << "1. We'll see - looking around the town for something interesting." << endl;
	cout << "2. Was just passing by the Ruins on my way to somewhere else, so I got my own big business anyway." << endl;
	cout << "3. Just looking for a nice old dungeon to raid. The usual, you know?" << endl;
	cout << "4. I've had enough adventures for the day. Mind if we talk about something else? Would appreciate it." << endl;
	cout << "5. Think I'll see myself around with the folk here." << endl;
	cout << "------------------------------------" << endl;
	cin >> action;

	if (action == 1) {
		cout << "He nods. 'Surprisingly, the town's been rather absent of urgent stuff for now... Of course, there's a dungeon or something being raided every now and then, but guess you oughta check the board Flink -the townmaster- has in front of the Hall." << endl;
		cout << "'Besides that, maybe check the adventurers and travellers around the place as well - you can always get yourself some action with those folks, eh?'" << endl;
	}

	else if (action == 2) {
		cout << "He raises his eyebrows. 'Oh, really? Got hired for something like espionage for one of the biggies?'" << endl;
		cout << "1. Sorta..." << endl;
		cout << "2. Nope - just heard there were big things cooking up around Heldan and decided to go see it." << endl;
		cout << "3. Would rather not talk 'bout it." << endl;
		cin >> action;

		if (action == 1) {
			cout << "'Oooh, bet you can't give the fella's name, can you?' He laughs. 'You don't have to answer that of course. I'll let you be - a night's stay is 5 gold.'" << endl;
			cout << "------------------------------------\n";
		}

		else if (action == 2) {
			cout << "'Yeah, you adventurers seem to always be lookin' for trouble, eh?' He gives some wine to another customer. 'Anyway, I'd say check the Traveller's Shop before you leave anytime soon. They got good stuff and some maps for the areas around here.'" << endl;
			cout << "------------------------------------\n";
		}

		else if (action == 3) {
			cout << "'Oh yeah?' he says. 'Have a good night anyway and maybe chat with the other folk 'round here.'" << endl;
			cout << "------------------------------------\n";
		}
	}

	else if (action == 3) {
		cout << "'A dungeon?' he says. 'You can get a map or a party for that - look for those people in the morning then. They always have dungeon maps.'" << endl;
	}

	else if (action == 4) {
		cout << "'I see.' he says. 'Whaddya wanna talk about then?'" << endl;
		cout << "1. What's going on around here? Heard some rumours about this place." << endl;
		cout << "2. Saw some weird people in dark robes. What's up with them?" << endl;
		cout << "3. I think I'll chat with the folk. Thanks for the drink." << endl;
		cin >> action;
		cout << "------------------------------------\n";

		if (action == 1) {
			cout << "'Those folks are spittin' bullshit. This place has been actually livable for some time now, and the nearest danger is the tale of that monster Aerius says he's seen.";
		}

		else if (action == 2) {
			cout << "'Good question...' he says. 'I dunno." << endl;
			cout << "You pay the nightly price of 5 gold and have a good night's sleep, and try not to think about them too much." << endl;
			gold = gold - 5;
			cout << "Remaining gold:" << gold << endl;
			cout << "------------------------------------\n";
		}

		else if (action == 3) {
			return inn_chat();
		}
	}

	else if (action == 5) {
		cout << "'Aight, your call. Try not to get annoyed by some of 'em.' he says." << endl;
		return inn_chat();
	}
	return 0;
}

int inn_chat() {
	
	
	cout << "At the inn, you see a bunch of the town regulars, as well as some of the travelers and adventurers talking about the fire. From the regulars, four old men play a game of cards among themselves, a couple of farmers are discussing the seasons to come, ";
	cout << "a young man is reading a thick tome, and a lady in long, purple robes is standing at the other side of him, seemingly reciting something." << endl;
	cout << "1. I'll check out what the travelers are talking about." << endl;
	cout << "2. I wonder what game those old men are playing." << endl;
	cout << "3. The farmers might be able to tell about the weather for today as well." << endl;
	cout << "4. Either the book or its worm probably has some good information." << endl;
	cout << "5. Whoah whoah whoah, that lady sure looks like a mage to me." << endl;
	LINE
	cin >> action;

	if (action == 1) {
		cout << "Around the fire, the one of the travelers -a middle-aged woman with grey already sprouting from her hair- tells the others that she's to deliver some supplies to Catanada, and warns the others of";
		cout << " the very buraeucratic guards they have around there. 'You gotta prove you are you and also where you come from,' she says. 'otherwise they really get shootin off those arrows.'" << endl;
		cout << "Others nod, and they take a sip from their drinks simultaneously, as having silently aggreed to do so." << endl;
		cout << "1. I'll ask some questions, then." << endl;
		cout << "2. I'll sit down and listen more. Maybe this Catanada place is worth going to." << endl;
		cout << "3. Boooooriiiing. The rest seems much more interesting." << endl;
		LINE
			cin >> action;

		if (action == 1) {
			cout << "What do you want to ask?" << endl;
			cout << "1. Do you know how to get to The Far End? Was thinking about going there." << endl;
			cout << "2. Mind if I take a trip with you to Catanada, lady?" << endl;
			cout << "3. The bartender says the Ruins have been calm for a while, but you guys know anything worth checking out 'round here?" << endl;
			cout << "4. You guys new around here too? I was just gonna ask where I should go before venturing off or something." << endl;
			cout << "------------------------------------\n";
			cin >> action;

			if (action == 1) {
				cout << "One of them turns his face. 'The Far End? What could you possibly have to do there, man?'" << endl;
				cout << "1. Just got this small thing to take care of." << endl;
				cout << "2. Wait for him to continue." << endl;
				cin >> action;
				if (action == 1) {
					cout << "He raises an eyebrow." << endl;
				}

				cout << "He takes a sip from his drink. 'You know, The Far End is nowhere near here, or anywhere to be fair. But if you wanna go there, sure, I'll write down some of the directions for you. You're welcome.'";
				cout << "The man grabs a sheet of parchment from his sack and gets his pen working, seemingly both writing and drawing things, he hands it over to you after about ten minutes. 'Hope this helps - whatever you have to do there, if you have anything,";
				cout << " be worth it. There's a reason not many are travelling that way.' He stands up and goes to get himself another drink. Checking the parchment, you can see that there are many directions and minor drawings about some 'confusing parts' scribbled about. You roll it up and save it for later use." << endl;
				cout << "------------------------------------\n";
				items far_end_map{ 0, 12, "The Far End Map", "Drawen by a man you met at the bar, this piece of parchment gives you enough directions and drawings to get to The Far End." };
				inventory.push_back(far_end_map);

				cout << "You thank the man and leave - The Far End is no longer a dream, now a mere possibility. What an upgrade., hurray." << endl;
				cout << "------------------------------------\n";
				cout << "QUEST UNLOCKED: THE FAR END" << endl;
				cout << "------------------------------------\n";

				//ADD FAR END STORYLINE
			}

			else if (action == 2) {
				cout << "The lady looks at you. 'Me? I'm just a courier, though, a mere nobody. Not going to be staying there for long, kid.'" << endl;
				cout << "1. I'm not anybody either - but got my sword and hands to help you." << endl;
				cout << "2. It's not like I'm gonna settle down, and Catanada really does sound nice." << endl;
				cout << "3. I'll just let her be then." << endl;
				cin >> action;

				if (action == 1) {
					cout << "Edges of her lips twist to a smile. 'So what? Think this old lady can't fight, kid? Been through all the bandits you can tell.' She checks a mechanical watch, taken out from her pocket just after that.";
					cout << " 'And looks like time I keep on doing that. Be careful out there, y'all.'" << endl;
				}

				else if (action == 2) {
					cout << "'Yeah? Good for you, because Catanada really is the place to do that.' she stares at you for some silent seconds. 'If you really aren't too interested in staying around here and pursuing tales, come with me.'";
					cout << " She takes a sip from her drink. 'Maybe I'll get you a job as well.'" << endl;
					cout << "You grab your sack and say, 'So, when we leavin'?' she laughs and stands up. 'Now good for you?' and you both leave the tavern to set off.";
					cout << "------------------------------------\n";
					cout << "QUEST UNLOCKED: CATANADA";
					cout << "------------------------------------\n";

		

					return gettingstarted();
				}

			}

			else if (action == 3) {
				cout << "Some looks are exchanged, then a young girl with farmer's clothes decides to make a comment. 'Well, he's right for sure, but you adventurers seem to be coming here for no reason whatsoever anyway. Might";
				cout << " as well check that monster our fella Aerius has been talking about then. Or the folks who'd been outside. They sure got some places to brawl through - they always do.'" << endl;
			}

			else if (action == 4) {
				cout << "A man, probably around thirty five now, smiles. 'Not quite a new guy here, though used to be just like you. Best check the Traveler's Shop for a couple maps, and that sword is begging to retire." << endl;
				cout << "You laugh and take a mental note of the two places, admitting his second point - the sword's nice but it's gotta at least be riddened of its rust. Leaving the place, you see him talk with a young girl.";
				cout << "You don't quite hear the whole conversation but can make out that he tells her to 'keep an eye on that fellow' and 'lend him a hand when he needs it soon enough.'" << endl;
				cout << "------------------------------------\n";
			}
		}

		else if (action == 2) {
			cout << "After taking a sip, one of the people around asks the lady, 'So, what are you delivering to Catanada?'" << endl;
			cout << "'Got this box full of many things: Potions, gems, a couple other things I don't remember right now and a spellbook. Yeah, there's that.' she says. You notice the lady in purple robes glancing at the word 'spellbook'.";
			cout << " 'Anyway,' she continues, ' heard that the place is a nice one - sure, they got their own fiddly papers and whatnot, but they say they got some nice nature over there. Trees, light green grass, clean rivers and whatnot.";
			cout << " But you know, can't stay near pretty things for too long. My delivery after that is to the North, around the mountains and their own small kingdoms. Going to be running between there for a while. Lucius knows what's coming after that.'" << endl;
			cout << "She takes out a mechanical watch from her pocket and checks the time. 'Oh boy, I sure have been talking a lot.' She takes her drink off the floor and leaves it on top of a barrel. 'I'll be going now. Nice seeing you guys - drink the rest of my ale." << endl;
			LINE
				cout << "1. Go after her and offer companionship to Catanada." << endl;
			cout << "2. I'll just go my way, stretch my legs or something." << endl;
			cin >> action;

			if (action == 1) {
				cout << "You take a couple quick steps after her, catching her right outside of the inn. 'Hey, lady, mind if I stick around with you for the trip? To Catanara? Promise I won't bite.'" << endl;
				cout << "She raises her eyebrows. 'Don't you have anywhere better to go? Oh wait, don't answer that, it's obvious. Hope you got yourself some spare clothes, because our walk isn't going to be the shortest. You have 5 minutes to get ready.'" << endl;
				LINE
					cout << "QUEST UNLOCKED: CATANADA" << endl;
				LINE


				return gettingstarted();
			}
		}

		else if (action == 3) {
			cout << "You stand up and rest your gaze upon the people here again." << endl;
			return inn_chat();
		}
	}

	else if (action == 2) {
		cout << "You approach the men, all lacking hair on their shiny heads, and observe the game. The cards are none of you've ever seen - there seems to be the numbers from 2 to 10, two different men's pictures, a lady and another card with nothing but a weird symbol on it: A" << endl;
		cout << "Taking a stool from the counter, you sit and observe the game. Obviously, the larger number takes the smaller ones, the man with another symbol -J- takes over them, the woman takes over J, the other man -this with another weird symbol: K-";
		cout << " is even superior to her, and the other card with no number or picture looks like it's the largest among them. The game's rules, though, are still impossible to understand." << endl;
		cout << "Finally, one of the looks at you and says, 'Can't tell what we're up to, can you, chap? Scoot over - maybe you'll end up learning how to not play the cards.' he nods at the man at the opposite side of the table. 'He didn't, eh?'";

		cout << "------------------------------------\n";

		cout << "They laugh and get playing. After multiple hours, you manage to grasp the basic concepts of how to conserve your cards depending on the goal and how to work around other's cards. Once they're done playing, the old man who spoke to you ";
		cout << "puts all cards back together and then into a little, wooden box marked with the symbol they called 'Spades'. He hands offers it to you. 'Got a whole lot of them when a nice merchant came here years ago. My wife's been telling me to get rid of them for Lucius knows how many years now,";
		cout << " so here you go. Have fun, chap.' You take the box and he walks away, following his friends." << endl;

		items card_deck{ 60,13, "Card Deck", "A deck of weird cards, gifted to you by a humorous old man back at the Ruins." };
		inventory.push_back(card_deck);

	}

	else if (action == 3) {

		cout << "The farmers are mostly men in their thirties, all muscular and tanned. One of them looks up and pulls a stool for you, and you sit down to listen. The weather, one says, is sure to be rainy tomorrow, seen the clouds.";
		cout << " The others nod, each taking a glance at you." << endl;
		LINE
			cout << "1. Well...don't mind me, I was just passing by. Better go get some rest, aye?" << endl;
		cout << "2. Haaave you people seen any weird things during these recent days? Some sorta monster, or polybears just feeding around?" << endl;
		cin >> action;

		if (action == 1) {
			return morning();
		}

		else if (action == 2) {
			cout << "'Suppose we did.' one of them says. 'Will you take care of it?'" << endl;
			cout << "1. Yes." << endl;
			cout << "2. No." << endl;
			cin >> action;

			if (action == 1) {
				cout << "'Good.' he sighs. 'The bloke talking around the center is right, it looks like. There is a monster.'";
				//Add in a quest.
			}

			else if (action == 2) {
				cout << "He shakes his head, and you leave to sleep." << endl;
				return morning();
			}
		}
	}

	else if (action == 4) {
		cout << "You approach the young boy -not even thirty, probably- reading his book, but he doesn't take notice of you.";
		cout << "'Hey.' you say and he looks up. 'Well, hello there. Care to explain why?" << endl;
		LINE
			cout << "1. What's that book you're reading?" << endl;
		cout << "2. Who's that lady in the robes?" << endl;
		cin >> action;


		if (action == 1) {
			cout << "He shuts the tome and shows you the cover which is adorned with eerie green patterns and some symbols you don't understand." << endl;
			cout << "'What is it?' you ask. 'Study. Magic stuff, dungeons, treasures, and most importantly-' he opens back to the page he was at and shows it to you, '-alchemy. Anything else?'" << endl;
			cout << "1. Magic stuff as if with, spells?" << endl;
			cout << "2. Dungeons, you said. What can you tell about them?" << endl;
			cout << "3. Alchemy? Never heard of that one." << endl;
			cin >> action;
			LINE
				spellbook old_parchment{ 40, 21, "Old Parchment", "An old parchment you  bought from a boy at the Ruins. You can cast a defensive shield spell with it." };
			shieldspell shield{ "Shield", "A spell to protect you from an attack.", 4 };
			old_parchment.spellsinside.push_back(shield);
			;

			if (action == 1) {
				cout << "'Uhh, yeah. You could say that, I guess.' He pauses for a moment. 'If you want, I can give the page to a simple spell for, let's say, 40 gold. Want it?'" << endl;
				cout << "1. Yes." << endl;
				cout << "2. Nah." << endl;
				cin >> action;

				if (action == 1 && gold >= 40) {
					cout << "You hand him the coins in exchange for the old piece of paper with vibrant letters across, which are identifiable for you. The boy goes back to reading his book. 'Good stuff.'" << endl;
					LINE
						cout << "Added Old Parchment into inventory" << endl;
					LINE
						inventory.push_back(old_parchment);

				}

				else if (action == 1 && gold < 40) {
					cout << "You do not have enough gold to buy this item!" << endl;
				}

				else if (action == 2) {
					cout << "He goes back to reading his book. 'G'night, then, I guess." << endl;
					cout << "He's right, because the night has fallen upon the sky. You yawn, slap 5 gold onto the counter, and go sleep in one of the rooms." << endl;
					gold = gold - 5;
					
					return morning();
				}
			}

			else if (action == 2) {
				cout << "'Honestly, a lot, especially with the ones around here. Catacombs. Lich graves. Haunted caves. Somehow, all are here - maybe not too surprising, considering the obvious history of this place. ";
				cout << "The catacombs seem to expand all the way to the North, but guess gotta visit Jinn later to see how that works out, as well as the entrance - not even a single clue for that matter. Besides those, there seems to be ";
				cout << "the grave of a lich and I think some adventurers were about to raid the place soon enough. Maybe you can just catch them in the morning and ask to tag along, and feed me what you've found in there. Anyway, no pressure for that matter.";
				cout << " I don't have much to say on the haunted caves, though, mostly because they're quite boring.'" << endl;
				cout << "1. When'll you visit Jinn?" << endl;
				cout << "2. Hmmm. I guess I could try to catch that party. Where would they be, you say?" << endl;
				cout << "3. No no no, I'd like to listen about the haunted caves. They left from the orc invasion?" << endl;
				cin >> action;
				LINE

					if (action == 1) {
						cout << "He scratches his head, and asks Herr for one of those purple drinks. 'I was thinking in about a month or so, depending on what else I can learn from the adventurers and whatnot. You sound you wanna come, though?'" << endl;
						cout << "1. Yeah, maybe?" << endl;
						cout << "2. Stay silent." << endl;
						cin >> action;

						if (action == 1) {
							cout << "'Mmm?' He thanks Herr for the drink and gives him some coins. 'And how're you gonna be helpful?' he asks." << endl;
							cout << "'Well, uhhh, I'm a good travel companion?' you suggest. He laughs and takes a sip from his drink. 'Tell you what, I've had an idea of some sort of group to explore this catacombs with, and you look just as dumb as I am.";
							cout << " And you  want in. Let's gather up a crew, - wait, name.' He chuckles. 'We don't even know each other's names. What a good fucking beginning for a party, isn' it,? '" << name << "' you say. '" << name << ".' He says. 'I'm Torlin. Now that we've got that out of the way-' He yawns and takes a look out of the windows. 'Nevermind,";
							cout << " I think we oughta sleep. Let's meet up here in the morning?" << endl;
							cout << "You nod, leave 5 gold on the counter, and go upstairs." << endl;
							gold = gold - 5;
						}
				}
			}
		}


		return 0;
	}

}

int morning() {

	return 0;
}

int main() {

	die();

	weapons rusty_sword{ 20,1,"Rusty Sword\n", "Nothing interesting - the good ol' broadsword always lets you deal with the monsters.", 7 };
	weapons old_axe{ 20,123, "Old Axe\n", "High highs and low lows. Welcome to the extreme style of the axe.", 10 };
	weapons shortswords{ 20,120, "Dual Shortswords\n", "Fast and fun, the dual shortswords are hard to use but hard to counter." ,3 };
	weapons endless_longbow{ 70,121, "Endless Longbow\n", "This magic longbow always produces its own arrows, perfect for a traveller.", 8 };

	
	cout << "Welcome to the Absolute Game, adventurer!\n";
	cout << "What is your name?" << endl;
	cin >> name;
	cout << "What kind of weapon do you want to use?" << endl;
	cout << "1. Classic Sword" << endl;
	cout << "2. Battleaxe" << endl;
	cout << "3. Dual Shortswords" << endl;
	cout << "4. Longbow" << endl;
	cin >> action;
	if (action == 1) {
		cout << rusty_sword.description << endl;
		inventory.push_back(rusty_sword);
	}

	else if (action == 2) {
		cout << old_axe.description << endl;
		inventory.push_back(old_axe);
	}
	
	else if (action == 3) {
		cout << shortswords.description << endl;
		inventory.push_back(shortswords);
	}

	else if (action == 4) {
		cout << endless_longbow.description << endl;
		inventory.push_back(endless_longbow);
	}



	cout << "Good luck," << name << "!" << endl;
	cout << "Your HP:" << hp << endl;
	cout << "Your gold:" << gold << endl;
	for (const auto& curr : inventory) {
		cout << "------------------------------------\n";
		cout << "Your inventory:" << endl;
		for (size_t index{}; index < inventory.size(); index++)
		{
			std::cout << (index) << ')' << inventory[index].itemname << '\n';
		}
		cout << "------------------------------------\n";
	}
	
	cout << "Type in '1' when you are ready or '2' to learn how the game works.";
	cin >> action;

	if (action == 1) {
		cout << "Your adventure starts here!" << endl;
		cout << "------------------------------------" << endl;
		
		return goblin();
	}

	else if (action == 2) {
		cout << "There will be options given to you throught the game. Pick the one you're the most interested in and enter the number before it without the dot - that's it! Have fun!" << endl;
		cout << "------------------------------------" << endl;

		return goblin();
	}


	else if (action == 3) {
		return ruins();
	}

	else if (action == 4) {
		return orc();
	}

	else if (action == 5) {
		return trading();
	}

	else if (action == 6) {
		return inn_chat();
	}

	else if (action == 7) {
		return morning();
	}

	else if (action == 8) {
		return gettingstarted();
	}
	return 0;
}

int dieTwenty(){
	srand(static_cast<unsigned int>(time(0)));

	int randomNumber = rand();
	int die = (randomNumber % 20) + 1;

	return die;
}

int dieTen()
{
	srand(static_cast<unsigned int>(time(0)));

	int randomNumber = rand();
	int die = (randomNumber % 9) + 1;

	return die;
}

int dieTwenty1()
{
srand(static_cast<unsigned int>(time(0)));

	int randomNumber = rand();
	int die = (randomNumber % 20) + 1;

	return die;
}

void runtime() {
	for (const auto& curr : inventory) {
		cout << "------------------------------------\n";
		cout << "Your inventory:" << endl;
		for (size_t index{}; index < inventory.size(); index++)
			{
			std::cout << (index) << ')' << inventory[index].itemname << '\n';
		}
			cout << "------------------------------------\n";
		}
		
}


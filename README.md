README — Project Black Fog

Overview
Black Fog is a text-based CLI game where the player lives a parallel life through a series of interactive scenarios.  
Each choice shapes the narrative path, but more importantly, allows the player to acquire real-world skills that remain useful outside the game.

The game does not teach through lessons, exercises, or theory:  
the player learns what the character learns.  
Learning is natural, contextual, and invisible.

---

Mission
Black Fog has a clear educational mission:

> Create a narrative experience where the player acquires real skills while living the character’s story, without perceiving learning as a separate activity.

The game uses everyday decisions, technical challenges, realistic situations, and personal growth paths to introduce concepts that matter in real life.

---

Core Concept
The player:

- lives a parallel life  
- makes decisions with narrative consequences  
- faces technical and practical problems  
- learns real skills (programming, security, time management, etc.)  
- internalizes what the character learns  

When the player stops playing, they realize that:

- they know how to use a VM  
- they understand cybersecurity concepts  
- their decision-making logic has improved  
- they gained basic programming knowledge  
- they developed problem-solving abilities  

The game becomes a bridge between fictional narrative and real personal growth.

---

Gameplay Structure
Black Fog is built on a scenario-based narrative structure:

- each scenario has an introductory text  
- each scenario presents a set of options  
- each option leads to a new scenario via a goto  
- each choice can introduce a real skill  

Example structure:

`json
{
	"story": {
		"root_chapter": {
			"text": "The alarm clock rings indicating the start of the day. It's 6:00 AM.",
			"options": ["Get out of bed", "Go back to sleep"],
			"goto": ["goodstart", "badstart"]
		}
	}
}
`

---

Educational Philosophy
Black Fog is based on three cognitive principles:

1. Contextual Learning
Skills are learned while facing narrative situations.

2. Incidental Learning
The player does not study: they live.

3. Skill Transfer
The abilities acquired by the character become abilities of the player.

---

Skills the Player Can Learn
The game can introduce real-world skills such as:

- C programming  
- virtual machine usage  
- cybersecurity fundamentals  
- time management  
- decision-making logic  
- problem solving  
- technical tool usage (Tor, VirtualBox, VMware, KVM, etc.)

---

Design Goals
- create an educational game that does not feel educational  
- make every choice meaningful  
- keep the narrative simple yet deep  
- enable real personal growth  
- ensure each scenario teaches something useful

---

Future Development
- expansion of scenarios  
- introduction of multiple narrative paths  
- flag and state variable system  
- thematic modules (programming, security, daily life)  
- expansion of the narrative engine in C

---

Developer
w-dev255
Text-based game developer
Focus: education through interactive narrative



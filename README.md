# IAS0360 Final Project - Topic 2
This project tackles the concept of recognizing and
classifying heat patterns in order to detect humans. The
heat data is collected from a thermal sensor attached to
the ceiling of a room. It measures any object which emits
heat. For example, the object could be an oven, human
being or any other heat-emitting object. In order to detect
humans, a model shall be created to distinguish heat
patterns. The hypothesis of this research is that humans
can be distinguished from other heat emitting objects
using a thermal sensor. As such, the project is an object
detection task.

## Deadline
Presentation: 13.12.2021
    
Final paper: 07.01.2021 23:59

## Report
https://www.overleaf.com/project/617665ffbc94254cf8ec4a41

## Presentation
https://docs.google.com/presentation/d/1TLgBtyyDolK1EsZuQ53GfDV2xGOMiX9MA92Uc6CJ1BQ/edit?usp=sharing

## Data
All the data is now in the repo. It is just a few MB.

## Labelling
Tobias: We consented to use `scripts/step1-data-understanding.ipynb`.
The sensors are treated independently, i.e., pictures with (alsmost) equal time stamps are not related to each other.
For manual annotation we show preceding and subsequent pictures to make the judgement easier.
We can derive binary classification (Human/Non-human) easily from the finer discrimination.


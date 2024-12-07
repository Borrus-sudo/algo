import { sumTailRecursive, sumNormalRecursive } from './divide_and_conquer.ts';
import { quickSort } from './quicksort.ts';
import { selectionSort } from './selectionsort.ts';
import { LinkedQueue, ArrayQueue } from './queue.ts';
import { search } from './search/rabbinKarp.ts';
import { karperkar } from './karpekar.ts';

const range = {
    start: 1,
    *[Symbol.iterator](end: number = 90000) {
        let counter = this.start;
        while (counter !== end) {
            yield Math.floor(Math.random() * end);
            counter++;
        }
        yield Math.floor(Math.random() * end);
    },
};

const input1 = [...range];
const input2 = [...input1];

/**
 * -----------------------------------------------
 *  SORTING ALGORITHMS CHECK
 * -----------------------------------------------
 */

console.time('Benchmark Quicksort');
console.log(quickSort(input1));
console.timeEnd('Benchmark Quicksort');

// console.time('Benchmark Mergesort');
// console.log(selectionSort(input2));
// console.timeEnd('Benchmark Mergesort');

/**
 * -----------------------------------------------
 *  TAIL RECURSION IMPLEMENTATION CHECK
 * -----------------------------------------------
 */

console.time('Benchmark Normal Recursion');
sumNormalRecursive([...range[Symbol.iterator](7000)]);
console.timeEnd('Benchmark Normal Recursion');

console.time('Benchmark Tail Recursion check');
sumTailRecursive([...range[Symbol.iterator](7000)]);
console.timeEnd('Benchmark Tail Recursion check');

/**
 * ---------------------------------------------------
 *  LinkedList vs Array IMPLEMENTATION CHECK for Queue
 * ---------------------------------------------------
 */

console.time('Benchmark Linked');
const linkedQueue = new LinkedQueue();
for (const number of range) {
    linkedQueue.enqueue(number);
}
for (const _ of range) {
    linkedQueue.dequeue();
}
console.timeEnd('Benchmark Linked');

console.time('Benchmark Array');
const arrayQueue = new ArrayQueue();
for (const number of range) {
    arrayQueue.enqueue(number);
}
for (const _ of range) {
    arrayQueue.dequeue();
}
console.timeEnd('Benchmark Array');

const inputString = `
To bait fish withal. If it will feed nothing
else, it will feed my revenge. He hath disgraced me
and hind‟red me half a million, laughed at my losses,
mocked at my gains, scorned my nation, thwarted my
bargains, cooled my friends, heated mine enemies –
and what‟s his reason? I am a Jew. Hath not a Jew
eyes? Hath not a Jew hands, organs, dimensions,
sense, affections, passions? – fed with the same
food, hurt with the same weapons, subject to the
same diseases, healed by the same means, warmed
and cooled by the same winter and summer as a
Christian is? If you prick us, do we not bleed? If
you tickle us, do we not laugh? If
If it were done, when ’tis done, then ’twere well
It were done quickly: if the assassination
Could trammel up the consequence, and catch
With his surcease success; that but this blow
Might be the be-all and the end-all – here,
But here, upon this bank and shoal of time,
We’d jump the life to come. But in these cases
We still have judgment here; that we but teach
Bloody instructions, which, being taught, return
To plague the inventor: this even-handed justice
Commends the ingredients of our poison’d chalice
To our own lips. He’s here in double trust:
First, as I am his kinsman and his subject,
Strong both against the deed
It must be by his death: and for my part,
I know no personal cause to spurn at him,
But for the general. He would be crown'd:
How that might change his nature, there's the question.
It is the bright day that brings forth the adder;
And that craves wary walking. Crown him?—that;—
And then, I grant, we put a sting in him,
That at his will he may do danger with.
The abuse of greatness is, when it disjoins
Remorse from power: and, to speak truth of Caesar,
I have not known when his affections sway'd
More than his reason. But 'tis a common proof,
That lowliness is young ambition's ladder,
Whereto the climber-upward turns his face;
But when he once attains the upmost round.
He then unto the ladder turns his back,
Looks in the clouds, scorning the base degrees
By which he did ascend. So Caesar may.
Then, lest he may, prevent. And, since the quarrel
Will bear no colour for the thing he is,
Fashion it thus; that what he is, augmented,
Would run to these and these extremities:
And therefore think him as a serpent's egg
Which, hatch'd, would, as his kind, grow mischievous,
And kill him in the shell.
; then, as his host,
Who should against his murderer shut the door,
Not bear the knife myself. Besides, this Duncan
Hath borne his faculties so meek, hath been
So clear in his great office, that his virtues
Will plead like angels, trumpet-tongu’d, against
The deep damnation of his taking-off;
And pity, like a naked new-born babe,
Striding the blast, or heaven’s Cherubins, hors’d
Upon the sightless couriers of the air,
Shall blow the horrid deed in every eye,
That tears shall drown the wind. I have no spur
To prick the sides of my intent, but only
Vaulting ambition, which o’erleaps itself
And falls on the other.
you poison us, do
we not die? And if you wrong us, shall we not
revenge? If we are like you in the rest, we will
resemble you in that. If a Jew wrong a Christian, what
is his humility? Revenge. If a Christian wrong a
Jew, what should his sufferance be by Christian
example? Why revenge! The villainy you teach me I
will execute, and it shall go hard but I will better
the instruction.`;

console.time('Benchmark RabbitKarp');
console.log(search(inputString, 'Christian', 24));  // greater than 30 causes the program to malfunction, possible overflow happening?
console.timeEnd('Benchmark RabbitKarp');

console.time('Benchmark Regex');
console.log(inputString.match(/Christian/g)?.length);
console.timeEnd('Benchmark Regex');


console.log(karperkar(9))
console.log(karperkar(297))
console.log(karperkar(91))


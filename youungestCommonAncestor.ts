// This is an input class. Do not edit.
class AncestralTree {
    name: string;
    ancestor: AncestralTree | null;

    constructor(name: string) {
        this.name = name;
        this.ancestor = null;
    }
}

function bfs(
    desc1: AncestralTree,
    desc2: AncestralTree,
    history: [string[], string[]],
    initialNames: [string, string]
): string {
    if (desc1.ancestor !== null) {
        if (history[1].includes(desc1.ancestor.name)) {
            return desc1.ancestor.name;
        } else {
            history[0].push(desc1.ancestor.name);
            if (desc2.ancestor !== null) {
                if (history[0].includes(desc2.ancestor.name)) {
                    return desc2.ancestor.name;
                } else {
                    history[1].push(desc2.ancestor.name);
                    return bfs(
                        desc1.ancestor,
                        desc2.ancestor,
                        history,
                        initialNames
                    );
                }
            } else {
                if (desc1.ancestor.name === initialNames[1]) {
                    return initialNames[1];
                } else {
                    return bfs(desc1.ancestor, desc2, history, initialNames);
                }
            }
        }
    } else {
        if (desc2.ancestor?.name === initialNames[0]) {
            return initialNames[0];
        } else {
            if (desc2.ancestor !== null) {
                return bfs(desc1, desc2.ancestor, history, initialNames);
            } else {
                return 'No Common Ancestor';
            }
        }
    }
}

export function getYoungestCommonAncestor(
    topAncestor: AncestralTree,
    descendantOne: AncestralTree,
    descendantTwo: AncestralTree
) {
    // Write your code here.
    console.log(JSON.stringify(descendantOne, null, 2));
    return topAncestor;
}

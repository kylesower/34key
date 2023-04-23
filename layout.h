#ifndef LAYOUT_PRINT_H
#define LAYOUT_PRINT_H
    const int layout_length = 53;
    char *my_layout[53] = {"MAIN","┌─────────┬─────────┬─────────┬─────────┬─────────┐                        ┌─────────┬─────────┬─────────┬─────────┬─────────┐","│    Q    │    W    │    F    │    P    │    G    │                        │    J    │    M    │    U    │    Y    │  BSPC   │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│    A    │    R    │    S    │    T    │    D    │                        │    H    │    N    │    E    │    I    │    O    │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│  _MISC  │    X    │    C    │    V    │    B    │                        │    Z    │    L    │    K    │   TAB   │   ENT   │","└─────────┴─────────┴─────────┴─────────┼─────────┼─────────┐    ┌─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘","                                        │  LOWER  │   SPC   │    │  LSFT   │  RAISE  │","                                        └─────────┴─────────┘    └─────────┴─────────┘","LOWER","┌─────────┬─────────┬─────────┬─────────┬─────────┐                        ┌─────────┬─────────┬─────────┬─────────┬─────────┐","│   ENT   │  CAPS   │  LCTL   │  LALT   │  LGUI   │                        │         │         │    [    │    ]    │  BSPC   │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│   ESC   │   HM    │   UP    │   ED    │         │                        │    _    │    (    │    )    │    {    │    }    │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│         │  LEFT   │  DOWN   │  RGHT   │         │                        │         │    /    │    \\    │         │         │","└─────────┴─────────┴─────────┴─────────┼─────────┼─────────┐    ┌─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘","                                        │         │   SPC   │    │  LSFT   │         │","                                        └─────────┴─────────┘    └─────────┴─────────┘","RAISE","┌─────────┬─────────┬─────────┬─────────┬─────────┐                        ┌─────────┬─────────┬─────────┬─────────┬─────────┐","│    `    │    &    │    *    │    ~    │    ,    │                        │         │    7    │    8    │    9    │  BSPC   │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│   ESC   │    $    │    %    │    ^    │    .    │                        │    +    │    4    │    5    │    6    │    0    │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│         │    !    │    @    │    #    │    =    │                        │    -    │    1    │    2    │    3    │   DEL   │","└─────────┴─────────┴─────────┴─────────┼─────────┼─────────┐    ┌─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘","                                        │         │   SPC   │    │  LSFT   │         │","                                        └─────────┴─────────┘    └─────────┴─────────┘","ADJUST","┌─────────┬─────────┬─────────┬─────────┬─────────┐                        ┌─────────┬─────────┬─────────┬─────────┬─────────┐","│   F1    │   F2    │   F3    │   F4    │         │                        │  VOLD   │  VOLU   │  MUTE   │ CG_SWAP │ CG_NORM │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│   F5    │   F6    │   F7    │   F8    │         │                        │ RBTVAR  │         │         │ SCRSHT  │         │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│   F9    │   F10   │   F11   │   F12   │         │                        │RBTNEWVAR│         │         │SCRSHTSV │         │","└─────────┴─────────┴─────────┴─────────┼─────────┼─────────┐    ┌─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘","                                        │         │         │    │         │         │","                                        └─────────┴─────────┘    └─────────┴─────────┘","MISC","┌─────────┬─────────┬─────────┬─────────┬─────────┐                        ┌─────────┬─────────┬─────────┬─────────┬─────────┐","│         │         │ QK_LEAD │         │  REDO   │                        │         │    ?    │    |    │    \"    │  BSPC   │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│   ALL   │         │    /    │    \\    │  FIND   │                        │         │    <    │    >    │    ;    │    '    │","├─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────────┼─────────┼─────────┼─────────┼─────────┤","│         │  UNDO   │   CUT   │  COPY   │  PASTE  │                        │         │    ,    │    .    │    :    │         │","└─────────┴─────────┴─────────┴─────────┼─────────┼─────────┐    ┌─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘","                                        │         │   SPC   │    │  LSFT   │         │","                                        └─────────┴─────────┘    └─────────┴─────────┘"};
    char *basic_layout = "MAIN\n,-------------------------------------------------.                        ,-------------------------------------------------.\n|    Q    |    W    |    F    |    P    |    G    |                        |    J    |    M    |    U    |    Y    |  BSPC   |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|    A    |    R    |    S    |    T    |    D    |                        |    H    |    N    |    E    |    I    |    O    |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|  _MISC  |    X    |    C    |    V    |    B    |                        |    Z    |    L    |    K    |   TAB   |   ENT   |\n`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'\n                                        |  LOWER  |   SPC   |    |  LSFT   |  RAISE  |\n                                        `-------------------'    `-------------------'\nLOWER\n,-------------------------------------------------.                        ,-------------------------------------------------.\n|   ENT   |  CAPS   |  LCTL   |  LALT   |  LGUI   |                        |         |         |    [    |    ]    |  BSPC   |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|   ESC   |   HM    |   UP    |   ED    |         |                        |    _    |    (    |    )    |    {    |    }    |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|         |  LEFT   |  DOWN   |  RGHT   |         |                        |         |    /    |    \\    |         |         |\n`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'\n                                        |         |   SPC   |    |  LSFT   |         |\n                                        `-------------------'    `-------------------'\nRAISE\n,-------------------------------------------------.                        ,-------------------------------------------------.\n|    `    |    &    |    *    |    ~    |    ,    |                        |         |    7    |    8    |    9    |  BSPC   |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|   ESC   |    $    |    %    |    ^    |    .    |                        |    +    |    4    |    5    |    6    |    0    |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|         |    !    |    @    |    #    |    =    |                        |    -    |    1    |    2    |    3    |   DEL   |\n`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'\n                                        |         |   SPC   |    |  LSFT   |         |\n                                        `-------------------'    `-------------------'\nADJUST\n,-------------------------------------------------.                        ,-------------------------------------------------.\n|   F1    |   F2    |   F3    |   F4    |         |                        |  VOLD   |  VOLU   |  MUTE   | CG_SWAP | CG_NORM |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|   F5    |   F6    |   F7    |   F8    |         |                        | RBTVAR  |         |         | SCRSHT  |         |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|   F9    |   F10   |   F11   |   F12   |         |                        |RBTNEWVAR|         |         |SCRSHTSV |         |\n`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'\n                                        |         |         |    |         |         |\n                                        `-------------------'    `-------------------'\nMISC\n,-------------------------------------------------.                        ,-------------------------------------------------.\n|         |         | QK_LEAD |         |  REDO   |                        |         |    ?    |    |    |    \"    |  BSPC   |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|   ALL   |         |    /    |    \\    |  FIND   |                        |         |    <    |    >    |    ;    |    '    |\n|---------+---------+---------+---------+---------|                        |---------+---------+---------+---------+---------|\n|         |  UNDO   |   CUT   |  COPY   |  PASTE  |                        |         |    ,    |    .    |    :    |         |\n`---------------------------------------+---------+---------.    ,---------+---------+---------------------------------------'\n                                        |         |   SPC   |    |  LSFT   |         |\n                                        `-------------------'    `-------------------'";
#endif
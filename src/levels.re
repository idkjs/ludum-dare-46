open Common;

let id = {
  let counter = ref(0);
  () => {
    incr(counter);
    counter^;
  };
};

let editorItemList = [
  Floor(Regular, Empty),
  Floor(Regular, Boulder(id(), Hard)),
  Floor(Regular, Boulder(id(), Hard)),
  Floor(Regular, Boulder(id(), Cracked)),
  Floor(Regular, Player(id(), Right, [Forward, Forward])),
  Floor(FilledPit(id()), Empty), // We don't need filled pit
  Wall,
  Pit,
];

let emptyLevel = {
  title: "Tutorial",
  items: editorItemList,
  map: Serialize.emptyMap(9, 8),
};

let boulderWall1 = {
  title: "Boulder Wall",
  items: [Floor(Regular, Boulder(id(), Hard))],
  map: [
    [Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall],
    [
      Wall,
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Wall,
    ],
    [
      Wall,
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Wall,
    ],
    [
      Wall,
      Floor(
        Regular,
        Player(
          id(),
          Right,
          [
            Forward,
            Forward,
            Forward,
            TurnLeft,
            Forward,
            Forward,
            TurnRight,
            Forward,
            TurnRight,
            Forward,
            Forward,
            Forward,
            Forward,
            Forward,
          ],
        ),
      ),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Wall,
      Floor(Regular, Empty),
      Wall,
    ],
    [
      Wall,
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Pit,
      Floor(Regular, Empty),
      Wall,
      Floor(Regular, Empty),
      Wall,
    ],
    [
      Wall,
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Pit,
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Wall,
    ],
    [
      Wall,
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Wall,
    ],
    [Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall],
  ],
};

let level1 = {
  title: "Tutorial",
  items: [
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
  ],
  map: [
    [
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
    ],
    [
      Floor(
        Regular,
        Player(
          id(),
          Right,
          [Forward, Forward, Forward, Forward, TurnLeft, Forward],
        ),
      ),
      Floor(Regular, Boulder(id(), Hard)),
      Floor(Regular, Boulder(id(), Hard)),
      Pit,
      Floor(Regular, Empty),
    ],
    [
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
    ],
  ],
};

let level2 = {
  title: "Tutorial",
  items: [
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
    Floor(Regular, Boulder(id(), Hard)),
  ],
  map: [
    [
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
    ],
    [
      Floor(
        Regular,
        Player(
          id(),
          Right,
          [Forward, Forward, Forward, Forward, TurnLeft, Forward],
        ),
      ),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Pit,
      Floor(Regular, Empty),
    ],
    [
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
      Floor(Regular, Empty),
    ],
  ],
};

let all = [boulderWall1];

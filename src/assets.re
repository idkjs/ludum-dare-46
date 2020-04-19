open Common;

let spriteSize = 120.;

let maybeInt = (f) => switch (int_of_float(f)) {
  | i => Some(i)
  | exception Failure(_) => None
};

let loadSpriteSheet = (filename, cb) =>
  Reasongl.Gl.File.readFile(
    ~filename,
    ~cb=jsonString => {
      open Json.Infix;
      let json = Json.parse(jsonString);
      let things = Json.get("frames", json) |?> Json.array |! "Expected field `frames` to be an array";
      let assets =
        List.fold_left(
          (assets, thing) => {
            let frame = Json.get("frame", thing) |! "Expected field `frame` in `frames` array";
            let x = Json.get("x", frame) |?> Json.number |?> maybeInt |! "Invalid field `x`";
            let y = Json.get("y", frame) |?> Json.number |?> maybeInt |! "Invalid field `y`";
            let w = Json.get("w", frame) |?> Json.number |?> maybeInt |! "Invalid field `w`";
            let h = Json.get("h", frame) |?> Json.number |?> maybeInt |! "Invalid field `h`";
            let name = Json.get("filename", thing) |?> Json.string |! "Invalid field `filename`";
            let name = List.hd(Reprocessing.Utils.split(name, ~sep='.'));
            StringMap.add(name, Sprite.({x, y, w, h}), assets);
          },
          StringMap.empty,
          things,
        );
      cb(assets)
    },
  );

let placeholder = (name, ~pos, ~width, ~height, env) => {
  Draw.fill(Constants.red, env);
  Draw.noStroke(env);
  Draw.rectf(~pos=Point.(toPair(pos)), ~width, ~height, env);
  Draw.text(
    ~body=name,
    ~pos=(int_of_float(pos.x), int_of_float(pos.y)),
    env,
  );
};

let drawSprite = (t, name, ~pos, ~scale=1.0, env) => {
  switch (StringMap.find(name, t.Sprite.map)) {
  | {x, y, w, h} =>
    let width = float_of_int(w) *. scale;
    let height = float_of_int(h) *. scale;
    Draw.subImagef(
      t.sheet,
      ~pos=Point.(toPair(pos - create(width /. 2., height /. 2.))),
      ~width,
      ~height,
      ~texPos=(x, y),
      ~texWidth=w,
      ~texHeight=h,
      env,
    );
  | exception Not_found =>
    placeholder(
      name,
      ~pos=Point.(pos - create(spriteSize /. 2, spriteSize /. 2)),
      ~width=spriteSize,
      ~height=spriteSize,
      env,
    )
  };
};
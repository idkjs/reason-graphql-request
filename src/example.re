[@bs.obj] external makeConfig : (~high: int, ~low: int=?, unit) => _ = "";

let c1 = makeConfig(~high=3, ());
let c2 = makeConfig(~low=2, ~high=3, ());

/* access them as Js.t objects! */
let high: int = c1##high;
let low: Js.undefined(int) = c1##low;

Js.log(low);
Js.log(high);
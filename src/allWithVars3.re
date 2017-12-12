/* see: https://reasonml.github.io/guide/language/object#tip--tricks for syntax 
Reason give the BS object value [%bs.obj {foo: bar}] a special syntax sugar: {"foo": bar}.
It looks like a quoted record, basically. Likewise for types: {. "foo": string}
*/

type variables = {
  .
  "filter": string
};

[@bs.module "graphql-request"]
external request : (~uri:string, ~query:string, ~vars:variables=?) => Js.Promise.t(Js.Json.t) = "request";

let uri = "https://api.graph.cool/simple/v1/cj9o4se940gsu0148s5a4helr";

let query = "
    query allCompanies($filter: String) {
        companies: allCompanies(filter: 
        { name_contains: $filter
        }) {
          id
          name
        }
      }";
/* no syntax sugar on js object dec */
let filtering2 = [%bs.obj {filter: "tast"}];

/* with syntax sugar on js object dec. same thing either way */
let filtering = {"filter": "tast"};
Js.log(filtering);
/* Js.log(variables); */
request(~uri=uri, ~query=query, ~vars=filtering2)
|> Js.Promise.then_(
  data => Js.Promise.resolve(Js.log(data))
);
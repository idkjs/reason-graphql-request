/* /* type filter =  Js.t({
  .
  filter: string
}); */
type variables = 
  | None
  | Some; 
/* Js.t({
  .
  filter: string
}); */
/* type option(variables) = None | Some(variables); */

[@bs.module "graphql-request"]
external request : (~uri:string, ~query:string, ~vars:variables) => Js.Promise.t(Js.Json.t) = "request";

/* let rec request = () => request(); */


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
  
/* let variables = Some([%bs.obj {filter: "tast"}]); */
let test = [%bs.obj {filter: "tast"}];

/* let variables = Some(Js.t({ . filter: "tast"})); */
let result = 
      switch variables {
        | None => request(uri, query)
        | Some(Js.t) => 
        let variables = Js.t({ . filter: string});
        request(uri, query, variables)
      };

/* Js.log(variables); */
result(uri, query, ())
|> Js.Promise.then_(
  data => Js.Promise.resolve(Js.log(data))
); */
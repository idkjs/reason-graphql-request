type variables = Js.t({
  .
  filter: string
});

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
  
let variables = [%bs.obj {filter: "tast"}];

/* Js.log(variables); */
request(~uri=uri, ~query=query, ~vars=variables)
|> Js.Promise.then_(
  data => Js.Promise.resolve(Js.log(data))
);
/* type query;

type gql = [@bs] (string => query); */

[@bs.module "graphql-request"]
external request : (~x:string, ~y:string) => Js.Promise.t(Js.Json.t) = "request";

/* we give the query (under the hood, it's a string) an opaque type. This way nobody can accidentally use it as a string  */
/* type query; */
let uri = "https://api.graph.cool/simple/v1/cj9o4se940gsu0148s5a4helr";

/* [@bs.module] external gql : gql = "graphql-tag"; */

let query = [%raw {|
    `query allCompanies($filter: String) {
        companies: allCompanies(filter: 
        { name_contains: $filter
        }) {
          id
          name
        }
      }`
|}];

request(~x=uri, ~y=query)
|> Js.Promise.then_(
  data => Js.Promise.resolve(Js.log(data))
);
/*
 * annotate the function with [@bs] so that it's statically verified to be fully
 * applied at each callsite. Better perf from fewer curryings. See more info on
 * `[@bs]` in the BS manual
 */
/* type gql = (string => query) [@bs]; */
/* let moviequery = [@bs] gql({|
    { query movie {
     Movie(title: "Inception") {
            releaseDate
            actors {
            name
            }
        }
    }}
    |});

request(~x=uri, ~y=moviequery)
|> Js.Promise.then_(
  data => Js.Promise.resolve(Js.log(data))
); */
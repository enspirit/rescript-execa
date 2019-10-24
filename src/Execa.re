[@bs.deriving abstract]
type child_process_result = {
  command: string,
  exitCode: int,
  stdout: string,
  stderr: string,
  isCanceled: bool,
  killed: bool,
  timedOut: bool,
  failed: bool,
};

[@bs.module "execa"] external commandSync: string => child_process_result = "commandSync";

% Tango Training for ELI-BL
% octave/matlab bindings
% reading attributes example
%
% C. Sacfuri
%


% use variables to handle device name and attibute name

devname = 'sys/tg_test/1';
attname = 'double_scalar';

res = tango_read_attribute(devname,attname);

if (tango_error == -1)
    % handle error !!!!!
    tango_print_error_stack;
else
    % reading ok, analyze result
    disp(sprintf('attribute %s value: %f',attname,res.value(1)));
    disp(sprintf('actual set point: %f',res.value(2)));
    disp(sprintf('quality factor: %s',res.quality_str));
end
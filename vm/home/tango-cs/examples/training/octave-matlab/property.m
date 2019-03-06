% Tango Training for ELI-BL
% octave/matlab bindings
% reading a property
%
% C. Sacfuri
%

% use variables to handle device name and property name
devname = 'sys/tg_test/1';
propname = 'TestProp';

prop= tango_get_property(devname,propname);
if (tango_error == -1)
    % handle error !!!!!
    tango_print_error_stack;
else
    % prop is a strutc
% the value field is a 'cell', cell elements are strings
    disp(sprintf('property size %d:',size(prop.value)))
    disp(sprintf('vaule 1: %s',prop.value{1,1}))
    disp(sprintf('vaule 2: %s',prop.value{1,2}))
end

%for writing  property

tango_put_property(devname,'TestProp',{'goofy','mickey'})

% but wrint propertiers from program should be done only if reaaly needed
% fo example after a calibration procedure - 


